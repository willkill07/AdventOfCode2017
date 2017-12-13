#include "Solution.hpp"
#include <iterator>
#include <algorithm>
#include <utility>
#include <vector>

template <>
void
solve<Day13>(bool part2, std::istream& is, std::ostream& os)
{
  std::vector<std::pair<int,int>> scan;
  for (int layer, range; (is >> layer).ignore(1,':') >> range; )
    scan.emplace_back(layer, range);
  if (part2) {
    int delay{0};
    while (std::any_of(std::begin(scan), std::end(scan),
             [delay] (auto const & p) {
               auto [layer, range] = p;
               return (delay + layer) % ((range - 1) * 2) == 0;
             }))
      ++delay;
    os << delay << '\n';
  } else {
    int sev{0};
    for (auto [layer, range] : scan)
      if (layer % ((range - 1) * 2) == 0)
        sev += layer * range;
    os << sev << '\n';
  }
}
