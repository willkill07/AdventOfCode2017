#include "Solution.hpp"
#include <vector>

template <>
template <bool part2>
void
Day<1>::solve(std::istream &is, std::ostream &os)
{
  std::vector<char> const values(std::istream_iterator<char>{is}, {});
  std::size_t const N{values.size()};
  std::size_t const offset{part2 ? N / 2 : 1};
  int sum{0};
  for (std::size_t i{0lu}; i < N; ++i) {
    if (values[i] == values[(i + offset) % N]) {
      sum += values[i] - '0';
    }
  }
  os << sum << '\n';
}
