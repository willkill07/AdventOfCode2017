#include "Solution.hpp"
#include <algorithm>
#include <functional>
#include <map>
#include <numeric>
#include <regex>

static std::regex const SPIN {R"(s(\d+))", std::regex::optimize},
                        EXCH {R"(x(\d+)/(\d+))", std::regex::optimize},
                        PART {R"(p(.)/(.))", std::regex::optimize};

template<>
void
solve<Day16>(bool part2, std::istream& is, std::ostream& os)
{
  std::string p(16, ' ');
  std::iota(std::begin(p), std::end(p), 'a');
  std::vector<std::function<void()>> cmds;
  for (std::string line; std::getline(is, line, ','); )
    if (std::smatch m; std::regex_match(line, m, SPIN))
      cmds.emplace_back([&p, i = std::stoi(m.str(1))] {
        std::rotate(std::begin(p), std::end(p) - i, std::end(p));
      });
    else if (std::regex_match(line, m, EXCH))
      cmds.emplace_back([&p, i = std::stoi(m.str(1)), j = std::stoi(m.str(2))] {
        std::swap(p[i], p[j]);
      });
    else if (std::regex_match(line, m, PART))
      cmds.emplace_back([&p, a = m.str(1)[0], b = m.str(2)[0]] {
        std::iter_swap(std::find(std::begin(p), std::end(p), a),
                       std::find(std::begin(p), std::end(p), b));
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
        break;
      }
    }
  } else {
    dance();
    os << p << '\n';
  }
}
