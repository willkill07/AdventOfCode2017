#include "Solution.hpp"
#include "timer.hpp"
#include <array>
#include <fstream>
#include <getopt.h>
#include <iomanip>
#include <regex>
#include <sstream>

enum time_options_t { NO_TIME = 0, TIME_IND = 1, TIME_TOTAL = 2 };

struct options_t {
  bool           part1{true}, part2{true};
  time_options_t time{NO_TIME};
  std::regex     filter{".*"};
};

template <Day>
double
timeSolve(bool, bool);

double
run(int, bool, time_options_t, std::ostream&);

options_t
parseArgs(int, char* []);

std::string
asString(int);

int
main(int argc, char* argv[])
{
  std::ofstream DEVNULL{"/dev/null"};
  options_t     options = parseArgs(argc, argv);
  double        totalTime{0.0};
  std::ostream  os{options.time == TIME_TOTAL ? DEVNULL.rdbuf() : std::cout.rdbuf()};
  for (int day{1}; day <= 25; ++day) {
    if (!std::regex_search(asString(day), options.filter))
      continue;
    os << asString(day) << ((options.part1 && options.part2) ? "\n" : ": ");
    if (options.part1) {
      if (options.part2)
        os << "Part 1: ";
      totalTime += run(day, false, options.time, os);
    }
    if (options.part2) {
      if (options.part1)
        os << "Part 2: ";
      totalTime += run(day, true, options.time, os);
    }
  }
  if (options.time == TIME_TOTAL)
    printf("  time: %.5lfms\n", totalTime);
  return EXIT_SUCCESS;
}

std::string
asString(int day)
{
  return (std::ostringstream{} << "Day" << std::setfill('0') << std::setw(2) << day).str();
}

template <Day DAY>
double
timeSolve(bool part2, bool time, std::ostream& os)
{
  double        resTime{0.0};
  std::ifstream is{"./inputs/" + asString(DAY) + ".txt"};
  if (time) {
    Timer<> t;
    solve<DAY>(part2, is, os);
    resTime = t.current<std::milli>();
    os.precision(5);
    os << "  time: ";
    os.setf(std::ios::fixed, std::ios::floatfield);
    os << resTime << "ms" << std::endl;
  } else
    solve<DAY>(part2, is, os);
  return resTime;
}

double
run(int day, bool part2, time_options_t time, std::ostream& os)
{
  using FnType = double(*)(bool, bool, std::ostream&);
  static std::array<FnType, 26> const dispatch {{ nullptr,
      &timeSolve<Day01>, &timeSolve<Day02>, &timeSolve<Day03>, &timeSolve<Day04>, &timeSolve<Day05>,
      &timeSolve<Day06>, &timeSolve<Day07>, &timeSolve<Day08>, &timeSolve<Day09>, &timeSolve<Day10>,
      &timeSolve<Day11>, &timeSolve<Day12>, &timeSolve<Day13>, &timeSolve<Day14>, &timeSolve<Day15>,
      &timeSolve<Day16>, &timeSolve<Day17>, &timeSolve<Day18>, &timeSolve<Day19>, &timeSolve<Day20>,
      &timeSolve<Day21>, &timeSolve<Day22>, &timeSolve<Day23>, &timeSolve<Day24>, &timeSolve<Day25>
  }};
  return dispatch[day](part2, time, os);
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
        const static std::vector<std::string> timeOptStrings{"no", "yes", "total"};
        if (long index{std::distance(timeOptStrings.begin(), std::find(timeOptStrings.begin(), timeOptStrings.end(), arg))}; index != 3) {
          options.time = static_cast<time_options_t>(index);
          break;
        }
        printf("ERROR: invalid time specified\n");
      }
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
        break;
    }
  }
  return options;
}
