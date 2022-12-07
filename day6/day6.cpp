#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>

#include <bitset>
namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day6.txt";

bool is_unique(const char* beg, const char* end)
{
  std::bitset<26> seen;

  const char* temp = beg;

  while (temp != end)
  {
    if (seen[*temp - 'a'])
    {
      return false;
    }
    else
    {
      seen.set(*temp - 'a');
    }
    ++temp;
  }
  return true;
}

int findUnique(std::string_view line, int dist)
{
  const char* beg = line.begin();
  const char* span = beg;

  std::advance(span, dist);

  while (span != line.end())
  {
    if (is_unique(beg, span))
    {
      return span - line.begin();
    }
    ++beg;
    ++span;
  }
}

void day6(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;
  line_sv = utils::getLine(line, end);

  std::cout << "P1: " << findUnique(line_sv, 4) << "\n";
  std::cout << "P2: " << findUnique(line_sv, 14) << "\n";
}
} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 6---\n";
  utils::MicroSecondTimer ms_timer;
  day6(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "us\n\n";
}