#include "Solution.hpp"
#include <algorithm>
#include <iterator>
#include <vector>

template <>
template <bool part2>
void
Day<5>::solve(std::istream &is, std::ostream &os)
{
  std::vector<int> inst{std::istream_iterator<int>{is}, {}};
  int index{0}, n{static_cast<int>(inst.size())};
  unsigned int steps{0};
  while (index >= 0 && index < n) {
    auto idx = static_cast<unsigned int>(index);
    ++steps;
    if (part2 && inst[idx] >= 3) {
      index += inst[idx]--;
    } else {
      index += inst[idx]++;
    }
  }
  os << steps << '\n';
}
