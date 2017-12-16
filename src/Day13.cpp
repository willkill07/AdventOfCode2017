#include "Solution.hpp"
#include <iterator>
#include <algorithm>
#include <type_traits>
#include <utility>
#include <vector>

template <unsigned int I, typename TupleLike>
struct View {
  std::tuple_element_t<I, TupleLike> val;
  View(TupleLike v) : val(std::get<I>(v)) {};
  bool operator<(const View &o) const { return val < o.val; }
};

auto
invalid (int delay = 0) {
  return [delay] (auto const & p) {
    auto [layer, range] = p;
    return (delay + layer) % ((range - 1) * 2) == 0;
  };
}

template <>
void
solve<Day13>(bool part2, std::istream& is, std::ostream& os)
{
  using Pair = std::pair<int, int>;
  std::vector<Pair> scan;
  for (int layer, range; (is >> layer).ignore(1,':') >> range; )
    scan.emplace_back(layer, range);
  if (part2) {
    int delay{0};
    std::sort(std::begin(scan), std::end(scan), std::less<View<1, Pair>>());
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
