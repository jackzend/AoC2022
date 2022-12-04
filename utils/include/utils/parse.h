#ifndef PARSE_H
#define PARSE_H
#include <charconv>
#include <fstream>
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

  if (str + 1 == end or str == end or *str == '\0')
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

inline std::vector<std::string_view> splitSVPtr(std::string_view str, std::string_view delims)
{
  std::vector<std::string_view> output;

  for (auto first = str.data(), second = str.data(), last = first + str.size();
       second != last && first != last; first = second + 1)
  {
    second = std::find_first_of(first, last, std::cbegin(delims), std::cend(delims));

    if (first != second)
      output.emplace_back(first, second - first);
  }

  return output;
}

// DOES NOT DO ERROR CHECKING
inline int stringViewToInt(const std::string_view sv)
{
  int i;
  auto result = std::from_chars(sv.data(), sv.data() + sv.size(), i);
  return i;
}

} // namespace utils

#endif