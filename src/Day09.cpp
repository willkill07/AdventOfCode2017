#include "Solution.hpp"

enum State {
  Default, Garbage, Ignore
};

template <>
void
solve<Day09>(bool part2, std::istream& is, std::ostream& os)
{
  State s{Default};
  int nest{0}, score{0}, gc{0};
  for (char c; is >> c; )
    switch (s) {
    case Default: switch (c) {
      case '<': s = Garbage;     continue;
      case '{': ++nest;          continue;
      case '}': score += nest--; continue;
    }
    case Garbage: switch (c) {
      case '!': s = Ignore;  continue;
      case '>': s = Default; continue;
      default:  ++gc;        continue;
    }
    case Ignore:
      s = Garbage;
    }
  os << (part2 ? gc : score) << '\n';
}
