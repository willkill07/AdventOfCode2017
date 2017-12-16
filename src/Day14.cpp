#include "Solution.hpp"
#include <array>
#include <numeric>
#include <sstream>
#include <iomanip>
#include <vector>
#include <cctype>
#include "util.hpp"

struct PairHash {
  std::size_t operator()(std::pair<int,int> const& p) const {
    return *reinterpret_cast<std::size_t const*>(&p.first);
  }
};

template <>
void
solve<Day14>(bool part2, std::istream& is, std::ostream& os)
{
  std::string input;
  is >> input;
  util::disjoint_set<std::pair<int,int>, PairHash> set;
  std::array<bool, 128> prev;
  std::fill(std::begin(prev), std::end(prev), false);
  for (int row = 0; row < 128; ++row) {
    std::string str{(std::ostringstream{} << input << "-" << std::to_string(row)).str()};
    auto hash = util::hash2array(util::knot_hash(str));
    for (int col = 0; col < 128; ++col) {
      if (hash[col]) {
        set.find({row, col});
        if (prev[col])
          set.join({row, col}, {row - 1, col});
        if (col > 0 && hash[col - 1])
          set.join({row, col}, {row, col - 1});
      }
    }
    std::copy(std::begin(hash), std::end(hash), std::begin(prev));
  }
  os << (part2 ? set.sets() : set.size()) << '\n';
}
