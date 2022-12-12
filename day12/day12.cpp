#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/graph.h>
#include <utils/parse.h>

namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day12.txt";

void day12(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;
  std::vector<char> grid;
  int rows = 0;
  int cols = 0;

  utils::Point2D start;
  utils::Point2D end_pt;

  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    cols = line_sv.size();
    int i = 0;
    for (auto c : line_sv)
    {
      if (c == 'S')
      {
        // process start
        start = {i, rows};
      }
      if (c == 'E')
      {
        // process end
        end_pt = {i, rows};
      }
      grid.push_back(c);
      ++i;
    }
    ++rows;
  }
}
} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 12---\n";
  utils::MicroSecondTimer ms_timer;
  day12(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "us\n\n";
}