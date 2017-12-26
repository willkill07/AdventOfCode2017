#include "Solution.hpp"
#include <tuple>
#include <utility>
#include <vector>

template <>
template <bool part2>
void
Day<19>::solve(std::istream &is, std::ostream &os)
{
  std::vector<std::string> grid;
  for (std::string line; std::getline(is, line); )
    grid.push_back(line);
  unsigned int const X(grid[0].size()), Y(grid.size());
  unsigned int x(grid[0].find("|")), y{0}, count{0};
  for (int dx{0}, dy{1}; grid[y][x] != ' '; x += dx, y += dy, ++count) {
    if (!part2 && std::isalpha(grid[y][x])) {
      os << grid[y][x];
    } else if (grid[y][x] == '+') {
      dx = -std::exchange(dy, dx);
      if (x + dx >= X || y + dy >= Y || grid[y + dy][x + dx] == ' ')
        dx = -dx, dy = -dy;
    }
  }
  if (part2)
    os << count;
  os << '\n';
}
