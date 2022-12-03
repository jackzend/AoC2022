#ifndef BASIC_TIMER_H
#define BASIC_TIMER_H
#include <chrono>
#include <iostream>
#include <ostream>

namespace utils
{

template <typename ChronoDuration>
class BasicTimer
{
public:
  using HRClock = std::chrono::high_resolution_clock;
  BasicTimer() : start_(HRClock::now()) {}
  typename ChronoDuration::rep getElapsed()
  {
    return ChronoDuration(HRClock::now() - start_).count();
  }
  void reset() { start_ = HRClock::now(); }

private:
  HRClock::time_point start_;
};

using MilliSecondTimer = BasicTimer<std::chrono::duration<float, std::milli>>;
using NanoSecondTimer = BasicTimer<std::chrono::duration<float, std::nano>>;
} // namespace utils
#endif