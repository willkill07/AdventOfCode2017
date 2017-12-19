#include "Solution.hpp"
#include <algorithm>
#include <array>
#include <iterator>
#include <sstream>
#include <thread>
#include <vector>

#include "duet_asm.hpp"

template <>
void
solve<Day18>(bool part2, std::istream& is, std::ostream& os)
{
  std::vector<program::instr> inst{std::istream_iterator<program::instr>{is}, {}};
  if (part2) {
    program     p0{inst, 0}, p1{inst, 1};
    std::thread t0{[&] { p0.run(p1); }};
    std::thread t1{[&] { p1.run(p0); }};
    t0.detach();
    t1.detach();

    while (!p0.deadlock() || !p1.deadlock())
      ;
    os << p0.send_count() / 2 << '\n';
  } else {
    program p{inst};
    while (true)
      if (auto[done, ret] = p.apply(); ret) {
        os << *ret << '\n';
        break;
      }
  }
}
