#ifndef _TIMER_HPP_
#define _TIMER_HPP_

#include <chrono>

template <typename Timing = std::chrono::steady_clock>
struct Timer {
  using Point = std::chrono::time_point<Timing>;

  Point begin;

  Timer()
    : begin{Timing::now()}
  {
  }

  template <typename Ratio>
  double
  current()
  {
    Point end{Timing::now()};
    return std::chrono::duration<double, Ratio>{end - begin}.count();
  }

};

#endif
