#include "Solution.hpp"
#include <vector>
#include "duet_asm.hpp"

template <>
template <bool part2>
void
Day<23>::solve(std::istream &is, std::ostream &os)
{
  std::vector<program::instr> instr {std::istream_iterator<program::instr>{is}, {}};
  if (part2) {
    auto ip = std::begin(instr);
    while (ip->cmd != "set" || std::get<char>(ip->arg1) != 'e')
      ++ip;
    *ip = {"set", 'g', 'b'};
    *(++ip) = {"mod", 'g', 'd'};
    *(++ip) = {"jnz", 'g', 8L};
    *(++ip) = {"set", 'f', 0L};
    *(++ip) = {"jnz", '1', 11L};
    while (ip->cmd != "set" || std::get<char>(ip->arg1) != 'g' || std::get<char>(ip->arg2) != 'd')
      ++ip;
    *ip = {"sqrt", 'g', 'b'};
    *(++ip) = {"sub", 'g', 'd'};
    (++ip)->cmd = "jgz";
  }
  program prog{instr};
  prog.set('a', part2);
  int mul_count{0};
  while (true) {
    auto [done, _] = prog.apply();
    if (!part2 && prog.curr().cmd == "mul")
      ++mul_count;
    if (done)
      break;
  }
  os << (part2 ? prog.value('h') : mul_count) << '\n';
}
