#include <algorithm>
#include <fstream>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

#include <utils/basic_timer.h>
#include <utils/parse.h>

namespace AoC2022
{

constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day1.txt";

void day1(const char* file)
{
  std::vector<char> buffer;

  utils::readParse(buffer, file);

  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view word;

  long sum = 0;
  std::vector<long> sum_vec;
  while (!(word = utils::getLine(line, end)).empty())
  {
    if (word[0] == '\n')
    {
      sum_vec.push_back(sum);
      sum = 0;
    }
    else
    {
      sum += std::stol(std::string(word));
    }
  }
  std::partial_sort(sum_vec.begin(), sum_vec.begin() + 3, sum_vec.end(), std::greater());

  std::cout << "P1: " << sum_vec[0] << "\n";
  std::cout << "P2: " << sum_vec[0] + sum_vec[1] + sum_vec[2] << "\n";
}

} // namespace AoC2022

using namespace AoC2022;
int main()
{
  utils::MilliSecondTimer ms_timer;

  day1(input_fp.begin());

  float elapsed = ms_timer.getElapsed();

  std::cout << "Elapsed: " << elapsed << "\n";
}
