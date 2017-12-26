#include <array>
#include <fstream>
#include <getopt.h>
#include <iomanip>
#include <optional>
#include <regex>
#include <sstream>

#include "Solution.hpp"
#include "timer.hpp"

#include "Day01.hpp"
#include "Day02.hpp"
#include "Day03.hpp"
#include "Day04.hpp"
#include "Day05.hpp"
#include "Day06.hpp"
#include "Day07.hpp"
#include "Day08.hpp"
#include "Day09.hpp"
#include "Day10.hpp"
#include "Day11.hpp"
#include "Day12.hpp"
#include "Day13.hpp"
#include "Day14.hpp"
#include "Day15.hpp"
#include "Day16.hpp"
#include "Day17.hpp"
#include "Day18.hpp"
#include "Day19.hpp"
#include "Day20.hpp"
#include "Day21.hpp"
#include "Day22.hpp"
#include "Day23.hpp"
#include "Day24.hpp"
#include "Day25.hpp"

enum time_options_t { NO_TIME = 0, TIME_IND = 1, TIME_TOTAL = 2 };

struct options_t {
  bool           part1{true}, part2{true};
  time_options_t time{NO_TIME};
  std::regex     filter{".*"};
};

options_t
parseArgs(int, char* []);

template <typename, bool>
double runInstance(bool, std::ostream&);

template <typename>
double runSingle(options_t const &, std::ostream&);

template <int ... Days>
double
runAll(options_t const & options, std::ostream& os, std::integer_sequence<int, Days...>) {
  return (... + runSingle<Day<Days>>(options, os));
}

int
main(int argc, char* argv[])
{
  std::ofstream DEVNULL{"/dev/null"};
  options_t     options = parseArgs(argc, argv);
  std::ostream  os{options.time == TIME_TOTAL ? DEVNULL.rdbuf() : std::cout.rdbuf()};
  double totalTime = runAll(options, os, ListOfDays{});
  if (options.time == TIME_TOTAL)
    printf("  time: %.5lfms\n", totalTime);
  return EXIT_SUCCESS;
}

template <typename DayToRun>
double runSingle(options_t const & options, std::ostream& os) {
  double totalTime {0.0};
  if (!std::regex_search(DayToRun::text(), options.filter))
    return totalTime;
  os << DayToRun::text() << ((options.part1 && options.part2) ? "\n" : ": ");
  if (options.part1) {
    if (options.part2)
      os << "Part 1: ";
    totalTime += runInstance<DayToRun, false>(options.time, os);
  }
  if (options.part2) {
    if (options.part1)
      os << "Part 2: ";
    totalTime += runInstance<DayToRun, true>(options.time, os);
  }
  return totalTime;
}

template <typename DayToRun, bool Part2>
double
runInstance(bool time, std::ostream& os)
{
  std::ifstream is{"./inputs/" + DayToRun::text() + ".txt"};
  if (time) {
    Timer<> t;
    DayToRun::template solve<Part2>(is, os);
    double resTime = t.current<std::milli>();
    os.precision(5);
    os << "  time: ";
    os.setf(std::ios::fixed, std::ios::floatfield);
    os << resTime << "ms" << std::endl;
    return resTime;
  } else {
    DayToRun::template solve<Part2>(is, os);
    return 0.0;
  }
}


options_t
parseArgs(int argc, char* argv[])
{
  options_t options;
  static char const* const shortOpts{"htnp:f:"};
  static const std::array<const ::option, 6> longOpts{{{"help", no_argument, nullptr, 'h'},
                                                       {"part", required_argument, nullptr, 'p'},
                                                       {"filter", required_argument, nullptr, 'f'},
                                                       {"time", required_argument, nullptr, 't'},
                                                       {nullptr, 0, nullptr, 0}}};
  int option{0};
  while ((option = getopt_long(argc, argv, shortOpts, longOpts.data(), nullptr)) != -1) {
    switch (option) {
      case 'p':
        if (optarg[0] == '1')
          options.part2 = false;
        else if (optarg[0] == '2')
          options.part1 = false;
        break;
      case 'f':
        options.filter = std::regex{optarg, std::regex::optimize};
        break;
      case 't': {
        std::string arg{optarg};
        static char const * const timeOptStrings[3] = {"no", "yes", "total"};
        if (long index{std::distance(timeOptStrings, std::find(timeOptStrings, timeOptStrings + 3, arg))}; index != 3) {
          options.time = static_cast<time_options_t>(index);
          break;
        }
        printf("ERROR: invalid time specified\n");
      }
        [[fallthrough]];
      case 'h':
      case '?':
        printf("Advent of Code - 2017\n"
               "---------------------\n"
               " -h|--help )\n    print help\n"
               " -p|--part=[1,2,all] )\n    only run parts specified [default = all]\n"
               " -f|--filter=<regex> )\n    filter day on regular expression [default = match all]\n"
               " -t|--time=[no,yes,total] )\n print timing of exection [default = no]\n"
               "\n"
               " Implementation by William Killian (c) 2016\n");
        exit(EXIT_SUCCESS);
    }
  }
  return options;
}
