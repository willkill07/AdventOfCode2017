#include "Solution.hpp"
#include <algorithm>
#include <iterator>
#include <numeric>
#include <set>
#include <sstream>

template <>
template <bool part2>
void
Day<4>::solve(std::istream &is, std::ostream &os)
{
  int sum{0};
  for (std::string line; std::getline(is, line); ) {
    std::istringstream iss{line};
    sum += std::all_of(
        std::istream_iterator<std::string>{iss}, {},
        [set = std::set<std::string>()] (std::string word) mutable {
          if constexpr (part2) {
            std::sort(word.begin(), word.end());
          }
          return set.insert(word).second;
        });
  }
  os << sum << '\n';
}
