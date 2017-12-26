#include "Solution.hpp"
#include <random>
#include <regex>

static std::regex const LINE { R"(Generator . starts with (\d+))", std::regex::optimize };

template <typename Generator>
auto gen(int init, int mask) {
  return [=, r = Generator(init)] () mutable {
    decltype(r()) i;
    do i = r(); while (i & mask);
    return i;
  };
}

template <>
template <bool part2>
void
Day<15>::solve(std::istream &is, std::ostream &os)
{
  auto parse = [&is] {
    std::string line;
    std::smatch m;
    std::getline(is, line);
    std::regex_match(line, m, LINE);
    return std::stoi(m.str(1));
  };
  auto A = gen<std::minstd_rand0>(parse(), part2 ? 0b11 : 0b0);
  auto B = gen<std::minstd_rand>(parse(), part2 ? 0b111 : 0b0);
  int N {part2 ? 5'000'000 : 40'000'000};
  int count{0};
  while (N--)
    if ((A() & 0xFFFF) == (B() & 0xFFFF))
      ++count;
  os << count << '\n';
}
