#ifndef PARSE_H
#define PARSE_H
#include <fstream>
#include <iomanip>
#include <string_view>
#include <vector>

namespace utils
{

inline std::string_view getLine(const char*& _str, const char* end)
{
  const char* str = _str;

  if (*str == '\n' || *str == '\r')
  {
    ++str;
    return (_str = str), std::string_view{"\n"};
  }

  if (str + 1 == end)
    return (_str = str), std::string_view{};

  const char* start = str;
  while (str != end && *str != '\n' && *str != '\r')
    ++str;

  size_t sz = static_cast<size_t>(str - start);
  return (_str = ++str), std::string_view{start, sz};
}

inline void readParse(std::vector<char>& buf, const char* file)
{
  std::ifstream in(file);
  in.seekg(0, std::ios::end);
  buf.resize(in.tellg());
  in.seekg(0, std::ios::beg);
  in.read(&buf[0], buf.size());
}

} // namespace utils

#endif