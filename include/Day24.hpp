#include "Solution.hpp"
#include <iterator>
#include <vector>

struct bridge {
  int port1, port2;
  bool avail;
};

std::istream& operator>> (std::istream& is, bridge & b) {
  (is >> b.port1).ignore(1, '/') >> b.port2;
  b.avail = true;
  return is;
}

template <typename Fn>
int
search(std::vector<bridge> & comp, Fn && f, int end = 0, int len = 0, int str = 0) {
  for (auto & [p1, p2, avail] : comp) {
    if (avail && (p1 == end || p2 == end)) {
      avail = false;
      search(comp, std::forward<Fn>(f), end ^ p1 ^ p2, len + 1, str + p1 + p2);
      avail = true;
    }
  }
  return f(len, str);
}

template <>
template <bool part2>
void
Day<24>::solve(std::istream &is, std::ostream &os)
{
  std::vector<bridge> bridges{std::istream_iterator<bridge>{is}, {}};
  if constexpr (part2) {
      os << search(bridges, [strength = 0, length = 0] (int l, int s) mutable {
          if (l > length) {
            strength = s, length = l;
          } else if (l == length) {
            strength = std::max(strength, s);
          }
          return strength;
        }) << '\n';
  } else {
    os << search(bridges, [strength = 0] (int, int s) mutable {
        return strength = std::max(strength, s);
      }) << '\n';
  }
}
