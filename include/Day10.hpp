#include "Solution.hpp"
#include <algorithm>
#include <array>
#include <initializer_list>
#include <iomanip>
#include <locale>
#include <numeric>
#include <vector>
#include <utility>

struct csv : std::ctype<char> {
  csv() : std::ctype<char>(get_table()) {}
  static mask const* get_table() {
    static mask rc[table_size];
    rc[static_cast<int>(',')] = std::ctype_base::space;
    rc[static_cast<int>('\n')] = std::ctype_base::space;
    return rc;
  }
};

template <>
template <bool part2>
void
Day<10>::solve(std::istream &is, std::ostream &os)
{
  std::vector<int> lengths;
  if (part2) {
    lengths.insert(lengths.end(), std::istream_iterator<char>{is}, {});
    lengths.insert(lengths.end(), {17, 31, 73, 47, 23});
  } else {
    is.imbue(std::locale{is.getloc(), new csv});
    lengths.insert(lengths.end(), std::istream_iterator<int>{is}, {});
    is.imbue(std::locale{is.getloc(), new std::ctype<char>});
  }

  int iters = part2 ? 64 : 1;
  std::array<unsigned char, 256> list;
  std::iota(std::begin(list), std::end(list), 0);

  unsigned char skip{0}, pos {0};
  while (iters--)
    for (unsigned char length : lengths) {
      std::reverse(std::begin(list), std::begin(list) + length);
      unsigned char delta = length + skip++;
      std::rotate(std::begin(list), std::begin(list) + delta, std::end(list));
      pos += delta;
    }
  std::rotate(std::begin(list), std::end(list) - pos, std::end(list));

  if (part2) {
    auto const [flags, fill] = std::pair(os.flags(std::ios::hex), os.fill('0'));
    for (auto b = std::begin(list); b != std::end(list); std::advance(b, 16))
      os << std::setw(2) << std::accumulate(b, std::next(b, 16), 0, std::bit_xor<void>());
    os.flags(flags), os.fill(fill);
  } else {
    os << list[0] * list[1];
  }
  os << '\n';
}
