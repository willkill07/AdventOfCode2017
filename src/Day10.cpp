#include "Solution.hpp"
#include <algorithm>
#include <array>
#include <initializer_list>
#include <iomanip>
#include <numeric>
#include <vector>

template <>
void
solve<Day10>(bool part2, std::istream& is, std::ostream& os)
{
  std::vector<int> lengths;
  if (part2) {
    for (char c; is >> c;)
      lengths.push_back(c);
    for (int i : {17, 31, 73, 47, 23})
      lengths.push_back(i);
  } else {
    int i;
    is >> i;
    lengths.push_back(i);
    while (is.ignore(1, ',') >> i)
      lengths.push_back(i);
  }

  int const iters = part2 ? 64 : 1;
  std::array<unsigned char, 256> list;
  std::iota(std::begin(list), std::end(list), 0);

  unsigned char skip = 0, pos = 0;
  for (int _{0}; _ < iters; ++_)
    for (unsigned char length : lengths) {
      std::reverse(std::begin(list), std::begin(list) + length);
      unsigned char delta = length + skip++;
      std::rotate(std::begin(list), std::begin(list) + delta, std::end(list));
      pos += delta;
    }
  std::rotate(std::begin(list), std::end(list) - pos, std::end(list));

  if (part2) {
    auto const flags = os.flags(std::ios::hex);
    for (auto b = std::begin(list); b != std::end(list); std::advance(b, 16))
      os << std::accumulate(b, b + 16, 0, std::bit_xor<void>());
    os.flags(flags);
  } else {
    os << list[0] * list[1];
  }
  os << '\n';
}
