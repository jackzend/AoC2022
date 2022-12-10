#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>
namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day9.txt";

void day9(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;
  while (!(line_sv = utils::getLine(line, end)).empty())
  {
  }
}
} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 9---\n";
  utils::MicroSecondTimer ms_timer;
  day9(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "us\n\n";
}