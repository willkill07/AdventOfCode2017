#include "Solution.hpp"
#include <algorithm>
#include <map>
#include <vector>

template <>
void
solve<Day06>(bool part2, std::istream& is, std::ostream& os)
{
  std::vector<int> banks{std::istream_iterator<int>{is}, {}};
  std::map<std::vector<int>, int> unique;
  for (int count{0}; unique.emplace(banks, count).second; ++count) {
    auto max = std::max_element(banks.begin(), banks.end());
    for (int iters{std::exchange(*max, 0)}; iters--; ++*max)
      if (++max == banks.end())
        max = banks.begin();
  }
  os << unique.size() - (part2 ? unique[banks] : 0) << '\n';
}
