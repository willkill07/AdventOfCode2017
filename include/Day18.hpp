#include "Solution.hpp"
#include "duet_asm.hpp"
#include <iterator>
#include <thread>
#include <vector>

template <>
template <bool part2>
void
Day<18>::solve(std::istream &is, std::ostream &os)
{
  std::vector<program::instr> inst{std::istream_iterator<program::instr>{is}, {}};
  os << [p0 = program{inst}, p1 = program{inst, 1}] () mutable {
    if constexpr (part2) {
      std::thread{&program::run, &p0, &p1}.detach();
      std::thread{&program::run, &p1, &p0}.detach();
      while (!p0.deadlock() || !p1.deadlock())
        ;
      return p1.send_count();
    } else {
      while (true) {
        auto [fin, val] = p0.apply();
        if (val)
          return static_cast<int>(val.value());
      }
    }
  }() << '\n';
}
