#include "Solution.hpp"
#include <algorithm>
#include <iterator>
#include <valarray>
#include <vector>
#include <utility>

struct particle {
  std::valarray<long> p{0,0,0}, v{0,0,0}, a{0,0,0};
};

template <>
template <bool part2>
void
Day<20>::solve(std::istream &is, std::ostream &os)
{
  std::vector<particle> ps;
  for (std::string line; std::getline(is, line); ) {
    particle p;
    std::sscanf(line.c_str(), "p=<%ld,%ld,%ld>, v=<%ld,%ld,%ld>, a=<%ld,%ld,%ld>",
                &p.p[0], &p.p[1], &p.p[2], &p.v[0], &p.v[1], &p.v[2], &p.a[0], &p.a[1], &p.a[2]);
    ps.emplace_back(std::move(p));
  }
  auto cmp = [] (particle const & p1, particle const & p2) {
    return std::abs(p1.a).sum() < std::abs(p2.a).sum();
  };
  if (part2) {
    auto const max = std::max_element(std::begin(ps), std::end(ps), cmp);
    auto const LIMIT = std::abs(max->a).sum();
    std::vector<bool> cs(ps.size(), true);
    for (long t{0}; t < LIMIT; ++t) {
      for (auto & p : ps) {
        p.p += (p.v += p.a);
      }
      for (auto [p1, c1] = std::pair(std::begin(ps), std::begin(cs));
           p1 != std::end(ps); std::advance(p1, 1), std::advance(c1, 1))
        if (*c1)
          for (auto [p2, c2] = std::pair(std::next(p1), std::next(c1));
               p2 != std::end(ps); std::advance(p2, 1), std::advance(c2, 1))
            if (*c2 && std::abs(p1->p - p2->p).sum() == 0)
              *c1 = *c2 = false;
    }
    os << std::count(std::begin(cs), std::end(cs), true) << '\n';
  } else {
    auto const min = std::min_element(std::begin(ps), std::end(ps), cmp);
    os << std::distance(std::begin(ps), min) << '\n';
  }
}
