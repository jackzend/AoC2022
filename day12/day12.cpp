#include <queue>
#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/graph.h>
#include <utils/parse.h>
#include <utils/third_party/gtl/phmap.hpp>

namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day12.txt";

inline size_t getIdx(int row, int col, int cols) { return row * cols + col; }

std::vector<utils::Point2D> getNeighbors(const std::vector<char>& grid, const utils::Point2D& pt,
                                         int rows, int cols)
{
  const std::array<utils::Point2D, 4> dirs = {{{-1, 0}, {1, 0}, {0, -1}, {0, 1}}};
  std::vector<utils::Point2D> neighbors;

  char curr = grid[getIdx(pt.y, pt.x, cols)];

  for (const auto& dir : dirs)
  {
    utils::Point2D neighbor = pt + dir;
    if (neighbor.x >= 0 && neighbor.y >= 0 && neighbor.x < cols && neighbor.y < rows)
    {
      char c = grid[getIdx(neighbor.y, neighbor.x, cols)];

      if ((int)c - (int)curr <= 1)
        neighbors.push_back(neighbor);
    }
  }

  return neighbors;
}

std::vector<utils::Point2D> breadthFirst(const std::vector<char>& grid, const utils::Point2D& start,
                                         const utils::Point2D& end, int rows, int cols)
{
  std::queue<utils::Point2D> stack;
  std::vector<bool> visited(rows * cols, false);
  // std::unordered_map<utils::Point2D, utils::Point2D, utils::Point2DHash> parent;
  gtl::flat_hash_map<utils::Point2D, utils::Point2D, utils::Point2DHash> parent;

  stack.push(start);
  visited[getIdx(start.y, start.x, cols)] = true;
  parent[start] = start;

  bool path_found = false;

  while (!stack.empty())
  {
    utils::Point2D curr = stack.front();
    stack.pop();

    if (curr == end)
    {
      path_found = true;
      break;
    }
    auto neighbors = getNeighbors(grid, curr, rows, cols);

    for (const auto& neighbor : neighbors)
    {
      if (!visited[getIdx(neighbor.y, neighbor.x, cols)])
      {
        visited[getIdx(neighbor.y, neighbor.x, cols)] = true;
        stack.push(neighbor);
        parent[neighbor] = curr;
      }
    }
  }

  if (!path_found)
    return {};

  auto curr = end;
  int path_len = 0;
  std::vector<utils::Point2D> path;
  while (curr != start)
  {
    curr = parent[curr];
    path.push_back(curr);
    ++path_len;
  }

  // std::reverse(path.begin(), path.end());
  // for (const auto& pt : path)
  //   std::cout << "(" << pt.x << ", " << pt.y << ")\n";

  return path;
}

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

  std::vector<utils::Point2D> a_ids;

  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    cols = line_sv.size();
    int i = 0;
    for (auto c : line_sv)
    {
      if (c == 'S')
      {
        // process start
        c = 'a';
        start = {i, rows};
      }
      if (c == 'E')
      {
        // process end
        c = 'z';
        end_pt = {i, rows};
      }
      if (c == 'a')
        a_ids.push_back({i, rows});
      grid.push_back(c);
      ++i;
    }
    ++rows;
  }

  auto path = breadthFirst(grid, start, end_pt, rows, cols);
  std::cout << "Path length: " << path.size() << '\n';

  int min_path_len = std::numeric_limits<int>::max();
  for (const auto& a_id : a_ids)
  {
    if (!(path = breadthFirst(grid, a_id, end_pt, rows, cols)).empty())
    {
      int path_len = path.size();
      // std::cout << "Path length: " << path_len << '\n';
      if (path_len < min_path_len and path_len != -1)
      {
        min_path_len = path_len;
        // std::cout << "New min path length: " << min_path_len << '\n';
      }
    }
  }
  std::cout << "Min path length: " << min_path_len << '\n';
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