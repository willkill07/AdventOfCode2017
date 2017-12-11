#include "Solution.hpp"
#include <algorithm>
#include <iterator>
#include <string>

constexpr int operator"" _enc(char const* c, unsigned long l) {
  int r{0};
  while (l--) r ^= *c++;
  return r;
}

constexpr int next(char const*& c) {
  int r{0};
  while (*c == ',') ++c;
  while (*c != '\0' && *c != ',') r ^= *c++;
  return r;
}

template <>
void
solve<Day11>(bool part2, std::istream& is, std::ostream& os) {
  std::string line{std::istream_iterator<char>{is}, {}};
  int max{0}, x{0}, y{0}, z{0};
  auto dist = [&] {
    return (std::abs(x) + std::abs(y) + std::abs(z)) / 2;
  };
  for (auto c = line.c_str(); *c; ) {
    switch (next(c)) {
      case "n"_enc:       ++y, --z; break;
      case "ne"_enc: ++x,      --z; break;
      case "se"_enc: ++x, --y;      break;
      case "s"_enc:       --y, ++z; break;
      case "sw"_enc: --x,      ++z; break;
      case "nw"_enc: --x, ++y;      break;
    }
    max = std::max(max, dist());
  }
  os << (part2 ? max : dist()) << '\n';
}
