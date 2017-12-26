#include "Solution.hpp"
#include <cstdio>
#include <unordered_map>

struct state {
  struct action {
    int write;
    char dir;
    char next;
  };
  action act[2];
};

template <typename T, typename Str>
T
read(std::istream& is, Str && str) {
  T data;
  std::string line;
  std::getline(is, line);
  std::sscanf(line.c_str(), std::forward<Str>(str), &data);
  return data;
}

template <>
template <bool part2>
void
Day<25>::solve(std::istream &is, std::ostream &os)
{
  if constexpr (part2) {
    os << "Happy Advent of Code 2017!" << '\n';
    return;
  } else {
    auto start = read<char>(is, "Begin in state %c.");
    auto steps = read<int>(is, "Perform a diagnostic checksum after %d steps.");

    std::unordered_map<char, state> states;
    for (std::string line; std::getline(is, line), is; ) {
      auto curr = read<char>(is, "In state %c:");
      state s;
      for (int i = 0; i < 2; ++i) {
        auto val = read<int>(is, "  If the current value is %d:");
        s.act[val] = state::action{
          read<int> (is, "    - Write the value %d."),
          read<char>(is, "    - Move one slot to the %c"),
          read<char>(is, "    - Continue with state %c.")
        };
      }
      states.emplace(curr, s);
    }

    std::unordered_map<int,int> tape;
    for (int cursor{0}; steps >= 0; --steps) {
      auto const & curr = states[start].act[tape[cursor]];
      tape[cursor] = curr.write;
      cursor += (curr.dir == 'l') ? -1 : 1;
      start = curr.next;
    }

    int checksum{0};
    for (auto [k,v] : tape)
      checksum += v;
    os << checksum << '\n';
  }
}
