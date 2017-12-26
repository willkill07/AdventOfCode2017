#include "Solution.hpp"
#include <array>
#include <cmath>
#include <unordered_map>

struct Point {
  int x{0}, y{0};
  operator std::uint64_t() const {
    auto as_u32 = [](int a) { return *reinterpret_cast<std::uint32_t*>(&a); };
    return static_cast<std::uint64_t>(as_u32(x)) << 32 | as_u32(y);
  }
  Point& operator+=(Point const& p) {
    x += p.x;
    y += p.y;
    return *this;
  }
  Point operator+(Point const& p) const {
    return Point{*this} += p;
  }
};

template <>
template <bool part2>
void
Day<3>::solve(std::istream &is, std::ostream &os)
{
  int num;
  is >> num;
  if (part2) {
    static std::array<Point, 8> const neighbors{{{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
    int limit{1}, step{0};
    bool sawTwo{true};
    Point loc{0, 0}, dir{1, 0};
    std::unordered_map<std::uint64_t, int> vals;
    vals[loc] = 1;
    while (vals[loc] <= num) {
      loc += dir;
      if (++step == limit) {
        step = 0;
        if ((sawTwo = !sawTwo)) {
          limit++;
        }
        dir = Point{-dir.y, dir.x};
      }
      int sum{0};
      for (auto const& n : neighbors) {
        sum += vals[loc + n];
      }
      vals[loc] = sum;
    }
    os << vals[loc] << '\n';
  } else {
    if (num == 1) {
      os << 0 << '\n';
    } else {
      auto revs = static_cast<int>(std::ceil(std::sqrt(num)) / 2);
      int offset{(num - (revs * 2 - 1) * (revs * 2 - 1)) % (revs * 2)};
      os << (revs + std::abs(offset - revs)) << '\n';
    }
  }
}
