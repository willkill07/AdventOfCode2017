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

  program(std::vector<instr> const& lst, long val = 0)
  : lst(lst) {
    reg['p' - 'a'] = val;
  }

  void run(program* p) {
    while (true) {
      auto[done, _] = apply(p);
      if (done)
        return;
    }
  }

  bool deadlock() const {
    return lst[ip].cmd == "rcv" && buf.empty();
  }

  int send_count() const {
    return sends;
  }

  std::pair<bool, std::optional<long>> apply(program* other = nullptr) {
    int next{1};
    std::optional<long> ret;
    if (ip >= lst.size())
      return {true, ret};
    auto const & [cmd, a1, a2] = lst[ip];
    switch (util::hash(cmd)) {
      case "set"_hash: at(a1)  = value_of(a2); break;
      case "add"_hash: at(a1) += value_of(a2); break;
      case "mul"_hash: at(a1) *= value_of(a2); break;
      case "mod"_hash: at(a1) %= value_of(a2); break;
      case "snd"_hash:
        ++sends;
        if (other)
          other->buf.enqueue(value_of(a1));
        else
          last = value_of(a1);
        break;
      case "rcv"_hash:
        if (other)
          at(a1) = buf.dequeue();
        else if (value_of(a1) != 0)
          ret = last;
        break;
      case "jgz"_hash:
        if (value_of(a1) > 0)
          next = value_of(a2);
    }
    ip += next;
    return {ip >= lst.size(), ret};
  }

  private:

  long& at(instr::arg const& a) {
    return reg[std::get<char>(a) - 'a'];
  }

  long value_of(instr::arg const& a) const {
    if (std::holds_alternative<long>(a))
      return std::get<long>(a);
    return reg[std::get<char>(a) - 'a'];
  }

  std::vector<instr> const& lst;
  std::array<long, 26> reg{{0}};
  util::safe_queue<long> buf;
  std::optional<long> last;
  unsigned int ip{0}, sends{0};
};

std::istream& operator>>(std::istream& is, program::instr::arg& v) {
  if (is.peek() == ' ')
    is.ignore(1);
  if (char c; std::isalpha(is.peek())) {
    is >> c; v = c;
  } else if (long val; std::isdigit(is.peek()) || is.peek() == '-') {
    is >> val; v = val;
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
