#ifndef PARSE_H
#define PARSE_H
#include <charconv>
#include <fstream>
#include <string_view>
#include <vector>
namespace utils
{

// this probably could be better. I didn't really bother fixing it
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

// Safe method for an efficient string_view splitter. Use this if you expect a number of tokens but
// want some error checking
inline void splitSVPtrInPlace(std::string_view str, std::string_view delims,
                              std::vector<std::string_view>& vec, size_t expected_num_of_tokens)
{

  if (vec.size() != expected_num_of_tokens)
  {
    vec.resize(expected_num_of_tokens);
  }

  size_t i = 0;
  for (auto first = str.data(), second = str.data(), last = first + str.size();
       second != last && first != last; first = second + 1)
  {
    second = std::find_first_of(first, last, std::cbegin(delims), std::cend(delims));

    if (first != second)
    {
      if (i < expected_num_of_tokens)
      {
        vec[i] = std::string_view{first, second - first};
      }
      else
      {
        vec.emplace_back(first, second - first);
      }
      ++i;
    }
  }
}

// vector.size() must == the number tokens expected in your string, otherwise this will break. Only
// use this if you know how many tokens you expect to get, otherwise use the other InPlace method
inline void splitSVPtrInPlaceNoCheck(std::string_view str, std::string_view delims,
                                     std::vector<std::string_view>& vec)
{
  size_t i = 0;
  for (auto first = str.data(), second = str.data(), last = first + str.size();
       second != last && first != last; first = second + 1)
  {
    second = std::find_first_of(first, last, std::cbegin(delims), std::cend(delims));

    if (first != second)
    {
      vec[i] = std::string_view{first, second - first};
      ++i;
    }
  }
}

// DOES NOT DO ERROR CHECKING
inline int stringViewToInt(const std::string_view sv)
{
  int i;
  std::from_chars(sv.data(), sv.data() + sv.size(), i);
  return i;
}

} // namespace utils

#endif