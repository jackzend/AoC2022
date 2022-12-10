#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/graph.h>
#include <utils/parse.h>

#include <compare>
#include <unordered_set>
namespace AoC2022
{
using namespace utils;
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day9.txt";

const Point2D getMoveMask(const std::string_view& dir)
{
  switch (dir[0])
  {
  case 'U':
    return {0, 1};
  case 'D':
    return {0, -1};
  case 'R':
    return {1, 0};
  case 'L':
    return {-1, 0};
  default:
    throw std::runtime_error("Invalid direction");
  }
}

Point2D getMove(Point2D& curr_head, Point2D& curr_tail)
{
  return {sgn(curr_head.x - curr_tail.x), sgn(curr_head.y - curr_tail.y)};
}

inline void step(Point2D& head, Point2D& tail)
{

  int man_dist = manhattanDistance(head, tail);
  double euclid_dist = euclideanDistance(head, tail);
  // if they are touching do nothing (0 is overlap, 1 is touching, 2 and diagonal is also touching)
  if (man_dist == 0 or man_dist == 1 or (man_dist == 2 and std::abs(euclid_dist - 1.414 < 0.01)))
    return;
  // tail goes to old head

  tail += getMove(head, tail);
}

void day9(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;
  std::vector<std::string_view> tokens;
  tokens.resize(2);

  utils::Point2D head{0, 0};
  utils::Point2D tail{0, 0};

  std::vector<Point2D> rope(10UL);

  std::unordered_set<utils::Point2D, Point2DHash> seen;
  std::unordered_set<utils::Point2D, Point2DHash> seen2;

  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    utils::splitSVPtrInPlaceNoCheck(line_sv, " ", tokens);
    int num_moves = utils::stringViewToInt(tokens[1]);

    for (int i = 0; i < num_moves; ++i)
    {
      head += getMoveMask(tokens[0]);
      step(head, tail);
      seen.insert(tail);

      rope[0] += getMoveMask(tokens[0]);
      for (int i = 0; i < rope.size() - 1; ++i)
      {
        step(rope[i], rope[i + 1]);
      }
      seen2.insert(rope.back());
    }
  }
  std::cout << "P1: " << seen.size() << '\n';
  std::cout << "P2: " << seen2.size() << '\n';
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