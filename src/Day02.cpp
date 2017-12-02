#include "Solution.hpp"
#include <algorithm>
#include <iterator>
#include <sstream>
#include <vector>

template <>
void
solve<Day02>(bool part2, std::istream& is, std::ostream& os)
{
  int sum(0);
  for (std::string line; std::getline(is, line); ) {
    std::istringstream iss{line};
    std::vector<int> const nums{std::istream_iterator<int>{iss}, {}};
    if (part2) {
      for (auto const v1 : nums) {
        for (auto const v2 : nums) {
          if (v1 != v2 && v1 % v2 == 0) {
            sum += v1 / v2;
          }
        }
      }
    } else {
      auto[min, max] = std::minmax_element(std::begin(nums), std::end(nums));
      sum += *max - *min;
    }
  }
  os << sum << '\n';
}
