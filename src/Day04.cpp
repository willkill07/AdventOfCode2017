#include "Solution.hpp"
#include <set>
#include <sstream>

template <>
void
solve<Day04>(bool part2, std::istream& is, std::ostream& os)
{
  int sum{0};
  for (std::string line; std::getline(is, line);) {
    sum += [&] {
      std::istringstream iss{line};
      std::set<std::string> s;
      for (std::string word; iss >> word;) {
        if (part2) {
          std::sort(word.begin(), word.end());
        }
        if (!s.insert(word).second) {
          return 0;
        }
      }
      return 1;
    }();
  }
  os << sum << '\n';
}
