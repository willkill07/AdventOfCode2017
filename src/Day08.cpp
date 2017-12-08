#include "Solution.hpp"
#include <algorithm>
#include <functional>
#include <regex>
#include <string_view>
#include <unordered_map>

static std::unordered_map<std::string_view, std::function<bool(int, int)>> const cmp{{
  {"==", std::equal_to<void>()},      {"!=", std::not_equal_to<void>()},
  {"<=", std::less_equal<void>()},    {"<", std::less<void>()},
  {">=", std::greater_equal<void>()}, {">", std::greater<void>()}}};

static std::unordered_map<std::string_view, std::function<int(int&, int)>> const apply{{
  {"inc", [](int& a, int b) { return a += b; }},
  {"dec", [](int& a, int b) { return a -= b; }}}};

template <>
void
solve<Day08>(bool part2, std::istream& is, std::ostream& os)
{
  std::unordered_map<std::string_view, int> vals;
  std::string var1, inc_dec, var2, op;
  int val1, val2, max{0};
  while (is >> var1 >> inc_dec >> val1 >> var2 >> var2 >> op >> val2)
    if (cmp.at(op)(vals[var2], val2))
      max = std::max(max, apply.at(inc_dec)(vals[var1], val1));
  if (!part2)
    max = std::max_element(vals.begin(), vals.end(),
                           [](auto& a, auto& b) { return a.second < b.second; })->second;
  os << max << '\n';
}
