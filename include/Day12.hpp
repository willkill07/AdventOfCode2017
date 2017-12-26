#include "Solution.hpp"
#include <algorithm>
#include <iterator>
#include <regex>
#include "util.hpp"

static std::regex const NUM {R"(\d+)", std::regex::optimize};

template <>
template <bool part2>
void
Day<12>::solve(std::istream &is, std::ostream &os)
{
  util::disjoint_set<int> set;
  for (std::string line; std::getline(is, line); ) {
    auto nums = std::sregex_iterator(std::begin(line), std::end(line), NUM);
    int prog {std::stoi(nums->str())};
    while (++nums != std::sregex_iterator()) {
      set.join(prog, std::stoi(nums->str()));
    }
  }
  os << (part2 ? set.sets() : set.size_of(0)) << '\n';
}
