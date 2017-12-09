#include "Solution.hpp"
#include <algorithm>
#include <unordered_map>

#define OP(X) { #X, [](int a, int b) { return a X b; } }
#define MOD(TAG, X) { TAG, [](int& a, int b) { return a X b; } }

template <typename V>
using Map = std::unordered_map<std::string, V>;

static Map<bool (*)(int, int)> const cmp{{OP(==), OP(!=), OP(<), OP(>), OP(<=), OP(>=)}};
static Map<int (*)(int&, int)> const apply{{MOD("inc", +=), MOD("dec", -=)}};

template <>
void
solve<Day08>(bool part2, std::istream& is, std::ostream& os)
{
  Map<int> vals;
  std::string var1, inc_dec, var2, op;
  int val1, val2, max{0};
  while (is >> var1 >> inc_dec >> val1 >> var2 >> var2 >> op >> val2)
    if (cmp.at(op)(vals[var2], val2))
      max = std::max(max, apply.at(inc_dec)(vals[var1], val1));
  if (!part2)
    max = std::max_element(vals.begin(), vals.end(), [](auto a, auto b) { return a.second < b.second; })->second;
  os << max << '\n';
}
