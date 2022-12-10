#include <map>
#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>

namespace AoC2022
{

constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day8.txt";

struct TreeInfo
{
  bool is_visible{false};
  int score{0};
};

inline TreeInfo visitTree(int val, size_t r, size_t c, std::vector<std::vector<int>>& grid)
{
  TreeInfo info;
  // check up
  bool up_clear = true;
  int up_score = 0;
  for (int i = r - 1; i >= 0; --i)
  {
    ++up_score;
    if (grid[i][c] >= val)
    {
      up_clear = false;
      break;
    }
  }
  if (up_clear)
    info.is_visible = true;

  // check down
  bool down_clear = true;
  int down_score = 0;
  for (int i = r + 1; i < grid.size(); ++i)
  {
    ++down_score;
    if (grid[i][c] >= val)
    {
      down_clear = false;
      break;
    }
  }
  if (down_clear)
    info.is_visible = true;

  // check left
  bool left_clear = true;
  int left_score = 0;
  for (int i = c - 1; i >= 0; --i)
  {
    ++left_score;
    if (grid[r][i] >= val)
    {
      left_clear = false;
      break;
    }
  }
  if (left_clear)
    info.is_visible = true;

  // check right
  bool right_clear = true;
  int right_score = 0;
  for (int i = c + 1; i < grid[r].size(); ++i)
  {
    ++right_score;
    if (grid[r][i] >= val)
    {
      right_clear = false;
      break;
    }
  }
  if (right_clear)
    info.is_visible = true;

  info.score = up_score * down_score * left_score * right_score;
  return info;
}

void day8(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;

  std::vector<std::vector<int>> grid;

  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    std::vector<int> row;

    for (auto& c : line_sv)
    {
      row.push_back(c - '0');
    }

    grid.push_back(row);
  }

  size_t visable_trees = 0;

  int max_score = 0;

  for (size_t i = 1; i < grid.size() - 1; ++i)
  {
    auto& row = grid[i];
    for (size_t j = 1; j < row.size() - 1; ++j)
    {
      auto val = row[j];
      auto info = visitTree(val, i, j, grid);
      if (info.is_visible)
      {
        ++visable_trees;
      }
      if (info.score > max_score)
      {
        max_score = info.score;
      }
    }
  }

  size_t edge = 2 * (grid[0].size() - 2) + 2 * (grid.size());
  visable_trees += edge; // top/bottom row

  std::cout << "P1: " << visable_trees << '\n';
  std::cout << "P2: " << max_score << '\n';
}
} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 8---\n";
  utils::MicroSecondTimer ms_timer;
  day8(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "us\n\n";
}