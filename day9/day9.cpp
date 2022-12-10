#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/graph.h>
#include <utils/parse.h>

#include <unordered_set>
namespace AoC2022
{
using namespace utils;
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day9.txt";

constexpr Point2D getMoveMask(const std::string_view& dir)
{
  constexpr std::array<std::pair<std::string_view, Point2D>, 4UL> move_mask_arr{
      {{"U", {0, 1}}, {"D", {0, -1}}, {"R", {1, 0}}, {"L", {-1, 0}}}};
  constexpr auto move_mask_map =
      utils::Map<std::string_view, Point2D, move_mask_arr.size()>{{move_mask_arr}};

  return move_mask_map.at(dir);
}

// constexpr double dist = euclideanDistance({0, 0}, {1, 2});

inline void step(Point2D& head, Point2D& tail, std::string_view dir)
{
  Point2D mask = getMoveMask(dir);

  auto temp = head;
  head += mask;

  int man_dist = manhattanDistance(head, tail);
  double euclid_dist = euclideanDistance(head, tail);
  // if they are touching do nothing (0 is overlap, 1 is touching, 2 and diagonal is also touching)
  if (man_dist == 0 or man_dist == 1 or (man_dist == 2 and std::abs(euclid_dist - 1.414 < 0.01)))
    return;
  // tail goes to old head
  tail = temp;
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
  std::unordered_set<utils::Point2D, utils::Point2DHash> seen;

  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    utils::splitSVPtrInPlaceNoCheck(line_sv, " ", tokens);
    int num_moves = utils::stringViewToInt(tokens[1]);
    for (int i = 0; i < num_moves; ++i)
    {
      step(head, tail, tokens[0]);
      seen.insert(tail);
    }
  }

  std::cout << "P1: " << seen.size() << '\n';
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