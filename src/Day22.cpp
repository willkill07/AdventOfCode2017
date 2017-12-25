#include "Solution.hpp"
#include <vector>
#include <unordered_map>
#include <utility>

struct point {
  int x, y;

  void rotL() { x = -std::exchange(y, x); }
  void rotR() { y = -std::exchange(x, y); }
  void reverse() { x = -x, y = -y; }

  point& operator+=(point const & d) {
    x += d.x, y += d.y;
    return *this;
  }

  bool operator==(point const & p) const {
    return x == p.x && y == p.y;
  }

  struct hash {
    std::size_t operator()(point const & c) const {
      return *reinterpret_cast<std::size_t const *>(&c.x);
    }
  };
};

template <>
void
solve<Day22>(bool part2, std::istream& is, std::ostream& os)
{
  std::unordered_map<point, char, point::hash> cluster;

  auto loc = [&] () -> point {
    int midX{-1}, y{0};
    for (std::string line; std::getline(is, line); ) {
      for (int x{0}; x < static_cast<int>(line.size()); ++x)
        if (line[x] == '#')
          cluster[{x, y}] = '#';
      midX = line.size() / 2; --y;
    }
    return {midX, y / 2};
  }();

  point dir{0,1};
  int bursts{0}, iterations{part2 ? 10000000 : 10000};
  while (iterations--) {
    if (auto p = cluster.find(loc); p != cluster.end()) {
      if (part2) {
        switch (p->second) {
          case 'W': ++bursts;      p->second = '#';  break;
          case '#': dir.rotR();    p->second = 'F';  break;
          case 'F': dir.reverse(); cluster.erase(p); break;
        }
      } else {
        dir.rotR(); cluster.erase(p);
      }
    } else if (part2) {
      dir.rotL(); cluster[loc] = 'W';
    } else {
      dir.rotL(); ++bursts; cluster[loc] = '#';
    }
    loc += dir;
  }
  os << bursts << '\n';
}
