#ifndef WILLIAM_KILLIAN_SOLUTION_HPP_
#define WILLIAM_KILLIAN_SOLUTION_HPP_

#include <iostream>
#include <string>

template <int DayOfAdvent>
struct Day {
  static std::string text() {
    return std::string{(DayOfAdvent < 10) ? "Day0" : "Day"} + std::to_string(DayOfAdvent);
  }

  template <bool Part2>
  static void solve(std::istream&, std::ostream&);
};

using ListOfDays = std::integer_sequence<int, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25>;

#endif
