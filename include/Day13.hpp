#include "Solution.hpp"
#include <iterator>
#include <algorithm>
#include <type_traits>
#include <utility>
#include <vector>
#include "util.hpp"

using Pair = std::pair<int, int>;

auto invalid (int delay = 0) {
  return [delay] (auto const & p) {
    auto [layer, range] = p;
    return (delay + layer) % ((range - 1) * 2) == 0;
  };
}

template <>
template <bool part2>
void
Day<13>::solve(std::istream &is, std::ostream &os)
{
  std::vector<Pair> scan;
  for (int layer, range; (is >> layer).ignore(1,':') >> range; )
    scan.emplace_back(layer, range);
  if (part2) {
    int delay{0};
    std::sort(std::begin(scan), std::end(scan), std::less<util::View<1, Pair>>());
    while (std::any_of(std::begin(scan), std::end(scan), invalid(delay)))
      ++delay;
    os << delay << '\n';
  } else {
    int sev{0};
    auto bad = invalid();
    for (auto const & p : scan)
      if (bad(p))
        sev += p.first * p.second;
    os << sev << '\n';
  }
}
