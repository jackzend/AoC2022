#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

namespace day1
{

constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/test.txt";
constexpr std::string_view newline_sv = "\n";

std::string_view getLine(const char*& _str, const char* end)
{

  const char* str = _str;

  if (*str == '\n' || *str == '\r')
  {
    ++str;
    _str = str;
    return newline_sv;
  }

  if (++str == end)
    return (_str = str), std::string_view{};

  const char* start = str;
  while (str != end && *str != '\n' && *str != '\r')
    ++str;

  _str = str;
  return std::string_view{start, str - start};
}

void parseInput(const char* file)
{
  std::vector<char> buffer;
  std::ifstream in(file);
  in.seekg(0, std::ios::end);
  buffer.resize(in.tellg());
  in.seekg(0, std::ios::beg);
  in.read(&buffer[0], buffer.size());

  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view word;

  int sum = 0;
  int max_sum = 0;
  while (!(word = getLine(line, end)).empty())
  {
    std::cout << word << std::endl;
  }
}

} // namespace day1

using namespace day1;
int main() { parseInput(input_fp.begin()); }
