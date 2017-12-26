#include "Solution.hpp"
#include <algorithm>
#include <functional>
#include <map>
#include <numeric>
#include <cstdio>
#include <vector>

template<>
template <bool part2>
void
Day<16>::solve(std::istream &is, std::ostream &os)
{
  std::string p(16, ' ');
  std::iota(std::begin(p), std::end(p), 'a');
  std::vector<std::function<void()>> cmds;
  for (std::string line; std::getline(is, line, ','); )
    if (int i; std::sscanf(line.c_str(), "s%d", &i))
      cmds.emplace_back([&p, i] {
        std::rotate(std::begin(p), std::prev(std::end(p), i), std::end(p));
      });
    else if (int j; std::sscanf(line.c_str(), "x%d/%d", &i, &j))
      cmds.emplace_back([&p, i, j] {
        std::iter_swap(std::begin(p) + i, std::begin(p) + j);
      });
    else if (char a, b; std::sscanf(line.c_str(), "p%c/%c", &a, &b))
      cmds.emplace_back([&p, a, b] {
        std::iter_swap(std::find(std::begin(p), std::end(p), a), std::find(std::begin(p), std::end(p), b));
      });

  auto dance = [&] {
    for (auto & cmd : cmds)
      cmd();
  };

  if (part2) {
    std::map<std::string, int> lookup;
    for (int rep{0}; lookup.emplace(p, rep++).second; )
      dance();
    int rem(1000000000 % lookup.size());
    for (auto const & [s,i] : lookup) {
      if (i == rem) {
        os << s << '\n';
        return;
      }
    }
  } else {
    dance();
    os << p << '\n';
  }
}
