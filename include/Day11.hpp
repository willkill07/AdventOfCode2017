#include "Solution.hpp"
#include <cctype>
#include <cmath>
#include <utility>

template <>
template <bool part2>
void
Day<11>::solve(std::istream &is, std::ostream &os)
{
  int x{0}, y{0}, z{0}, dist{0}, max{0};
  for (char c, v{0}; is >> c; ) {
    if (std::isalpha(c)) {
      v ^= c;
      continue;
    }
    switch(std::exchange(v, 0)) {
      case 'n'      :      ++y, --z; break;
      case 'n' ^ 'e': ++x,      --z; break;
      case 's' ^ 'e': ++x, --y     ; break;
      case 's'      :      --y, ++z; break;
      case 's' ^ 'w': --x,      ++z; break;
      case 'n' ^ 'w': --x, ++y     ; break;
    }
    dist = (std::abs(x) + std::abs(y) + std::abs(z)) / 2;
    if (part2)
      max = std::max(max, dist);
  }
  os << (part2 ? max : dist) << '\n';
}
