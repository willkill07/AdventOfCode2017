#ifndef WILLIAM_KILLIAN_DUET_ASM_HPP
#define WILLIAM_KILLIAN_DUET_ASM_HPP

#include <iostream>
#include <optional>
#include <string>
#include <utility>
#include <variant>
#include <vector>

#include "util.hpp"

struct program {

  struct instr {
    using arg = std::variant<long, char>;
    std::string cmd;
    arg         arg1, arg2;
  };

  program(std::vector<instr> const& lst, long val = -1)
  : lst(lst) {
    if (val >= 0) {
      reg['p'] = val;
    }
  }

  void run(program& p) {
    while (true) {
      auto[done, _] = apply(&p);
      if (done)
        break;
    }
  }

  bool deadlock() const {
    return lst[ip].cmd == "rcv" && buf.empty();
  }

  int send_count() const {
    return sends;
  }

  int recv_count() const {
    return recvs;
  }

  std::pair<bool, std::optional<long>>
  apply(program* other = nullptr) {
    std::optional<long> ret;
    if (ip >= lst.size()) {
      return {true, ret};
    }
    auto & [cmd, a1, a2] = lst[ip];
    if (cmd == "snd") {
      if (other) {
        other->buf.enqueue(value_of(a1));
      } else {
        last = value_of(a1);
      }
      ++sends;
    } else if (cmd == "rcv") {
      if (other) {
        at(a1) = buf.dequeue();
      } else if (value_of(a1) != 0) {
        ret = last;
      }
      ++recvs;
    } else if (cmd == "set") {
      at(a1) = value_of(a2);
    } else if (cmd == "add") {
      at(a1) += value_of(a2);
    } else if (cmd == "mul") {
      at(a1) *= value_of(a2);
    } else if (cmd == "mod") {
      at(a1) %= value_of(a2);
    } else if (cmd == "jgz") {
      ip += ((value_of(a1) > 0) ? value_of(a2) - 1 : 0);
    }
    ++ip;
    return {false, ret};
  }

  private:

  long& at(instr::arg const& a) {
    return reg[std::get<char>(a) - 'a'];
  }

  long value_of(instr::arg const& a) const {
    return (std::holds_alternative<long>(a)) ? std::get<long>(a) : reg[std::get<char>(a) - 'a'];
  }

  std::vector<instr> const& lst;
  std::array<long, 26>      reg{{0}};
  util::safe_queue<long>    buf;
  std::optional<long>       last;
  unsigned int              ip{0}, sends{0}, recvs{0};
};

std::istream& operator>>(std::istream& is, program::instr::arg& v) {
  if (is.peek() == ' ')
    is.ignore(1);
  if (std::isalpha(is.peek())) {
    char c;
    is >> c;
    v = c;
  } else if (std::isdigit(is.peek()) || is.peek() == '-') {
    long val;
    is >> val;
    v = val;
  }
  return is;
}

std::istream& operator>>(std::istream& is, program::instr& i) {
  if (is.peek() == '\n')
    is.ignore(1);
  is >> i.cmd >> i.arg1 >> i.arg2;
  return is;
}

#endif
