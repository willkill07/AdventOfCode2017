#include "Solution.hpp"
#include <vector>

template <>
void
solve<Day19>(bool part2, std::istream& is, std::ostream& os)
{
  std::vector<std::string> grid;
  for (std::string line; std::getline(is, line); )
    grid.push_back(line);
  unsigned long x{grid[0].find("|")}, y{0}, count{0};
  char dir{'D'};
  while (grid[y][x] != ' ') {
    ++count;
    if (grid[y][x] == '+') {
      if (dir == 'D' || dir == 'U') {
        dir = (x > 0 && grid[y][x-1] != ' ') ? 'L' : 'R';
      } else {
        dir = (y > 0 && grid[y-1][x] != ' ') ? 'U' : 'D';
      }
    } else if (!part2 && std::isalpha(grid[y][x])) {
      os << grid[y][x];
    }
    switch (dir) {
      case 'D': ++y; break;
      case 'U': --y; break;
      case 'R': ++x; break;
      case 'L': --x; break;
    }
  }
  if (part2)
    os << count;
  os << '\n';
}
