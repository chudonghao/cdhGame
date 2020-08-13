//
// Created by chudonghao on 2020/8/9.
//

#ifndef CDHGAME_38C70B65D8104C4F801B31D488518736_
#define CDHGAME_38C70B65D8104C4F801B31D488518736_

#include <iostream>
#include <sstream>
#include <utility>

namespace cdhRt {
enum LogLevel {
  LOG_LEVEL_DEBUG,
  LOG_LEVEL_INFO,
  LOG_LEVEL_WARNING,
  LOG_LEVEL_ERROR,
  LOG_LEVEL_FATAL,
};
struct Log {
  Log(std::string file, int line, LogLevel ll) : file(std::move(file)), line(line), logLevel(ll) {}
  ~Log() {
    switch (logLevel) {
    case LOG_LEVEL_DEBUG:
    case LOG_LEVEL_INFO:
    case LOG_LEVEL_WARNING:
    default:
      std::cout << file << ':' << line << ' ' << ss.str() << std::endl;
      break;
    case LOG_LEVEL_ERROR:
    case LOG_LEVEL_FATAL:
      std::cerr  << file << ':' << line << ' ' << ss.str() << std::endl;
      break;
    }
  }
  template <typename T> Log &operator<<(T &&t) {
    ss << std::forward<T>(t);
    return *this;
  };
  std::string file;
  int line;
  std::stringstream ss;
  LogLevel logLevel;
};
} // namespace cdhRt

#endif // CDHGAME_38C70B65D8104C4F801B31D488518736_
