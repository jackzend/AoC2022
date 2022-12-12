#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/graph.h>
#include <utils/parse.h>

namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day12_sample.txt";

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

  // x is col, y is row
  auto get_idx = [cols](const utils::Point2D& pos) { return (size_t)(pos.x + pos.y * cols); };

  std::function<std::vector<utils::Point2D>(const std::vector<char>&, const utils::Point2D&)>
      gen_neighbors =
          [get_idx, rows, cols](const std::vector<char>& grid, const utils::Point2D& pos)
  {
    std::vector<utils::Point2D> neighbors;
    char curr = grid[get_idx(pos)];

    for (int i = 0; i < 4; ++i)
    {
      utils::Point2D neighbor = pos;
      switch (i)
      {
      case 0:
        neighbor.y -= 1;
        break;
      case 1:
        neighbor.y += 1;
        break;
      case 2:
        neighbor.x -= 1;
        break;
      case 3:
        neighbor.x += 1;
        break;
      }

      if (neighbor.x < 0 || neighbor.y < 0 || neighbor.x >= cols || neighbor.y >= rows)
      {
        continue;
      }

      char neighbor_val = grid[get_idx(neighbor)];
      if (curr == 'S')
      {
        curr = 'a';
      }
      else if (curr == 'E')
      {
        curr = 'z';
      }
      int val = neighbor_val - curr;
      if (val > 1)
      {
        continue;
      }

      neighbors.push_back(neighbor);
    }

    return neighbors;
  };

  int num_steps = utils::dijkstra<std::vector<char>, utils::Point2D, utils::Point2DHash>(
      grid, start, end_pt, gen_neighbors);

  std::cout << "P1: " << num_steps << '\n';
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