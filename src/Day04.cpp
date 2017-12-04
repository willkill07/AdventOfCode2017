#include "Solution.hpp"
#include <algorithm>
#include <iterator>
#include <numeric>
#include <set>
#include <sstream>

template <>
void
solve<Day04>(bool part2, std::istream& is, std::ostream& os)
{
  int sum{0};
  for (std::string line; std::getline(is, line); ) {
    std::istringstream iss{line};
    sum += std::all_of(
        std::istream_iterator<std::string>{iss}, {},
        [part2, set = std::set<std::string>()] (std::string word) mutable {
          if (part2) {
            std::sort(word.begin(), word.end());
          }
          return set.insert(word).second;
        });
  }
  os << sum << '\n';
}
