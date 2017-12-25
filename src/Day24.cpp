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
search(int end, int len, int str, std::vector<bridge> & comp, Fn && f) {
  for (auto & [p1, p2, avail] : comp) {
    if (avail && (p1 == end || p2 == end)) {
      avail = false;
      search(end ^ p1 ^ p2, len + 1, str + p1 + p2, comp, std::forward<Fn>(f));
      avail = true;
    }
  }
  return f(len, str);
}

template <>
void
solve<Day24>(bool part2, std::istream& is, std::ostream& os)
{
  std::vector<bridge> bridges{std::istream_iterator<bridge>{is}, {}};
  auto app = [part2, strength = 0, length = 0] (int l, int s) mutable {
    if (part2) {
      if (l > length) {
        strength = s, length = l;
      } else if (l == length) {
        strength = std::max(strength, s);
      }
    } else {
      strength = std::max(strength, s);
    }
    return strength;
  };
  os << search(0, 0, 0, bridges, app) << '\n';
}
