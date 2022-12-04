#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>
namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day2.txt";

using namespace std::string_view_literals;

static constexpr std::array<std::pair<int, int>, 9UL> score_arr_p1{{{'A' * 'X', 4},
                                                                    {'A' * 'Y', 8},
                                                                    {'A' * 'Z', 3},
                                                                    {'B' * 'X', 1},
                                                                    {'B' * 'Y', 5},
                                                                    {'B' * 'Z', 9},
                                                                    {'C' * 'X', 7},
                                                                    {'C' * 'Y', 2},
                                                                    {'C' * 'Z', 6}}};

static constexpr auto score_map_p1 = utils::Map<int, int, score_arr_p1.size()>{{score_arr_p1}};

static constexpr std::array<std::pair<int, int>, 9UL> score_arr_p2{{{'A' * 'X', 3},
                                                                    {'A' * 'Y', 4},
                                                                    {'A' * 'Z', 8},
                                                                    {'B' * 'X', 1},
                                                                    {'B' * 'Y', 5},
                                                                    {'B' * 'Z', 9},
                                                                    {'C' * 'X', 2},
                                                                    {'C' * 'Y', 6},
                                                                    {'C' * 'Z', 7}}};

static constexpr auto score_map_p2 = utils::Map<int, int, score_arr_p2.size()>{{score_arr_p2}};

void day2(const char* file)
{
  std::vector<char> buffer;

  utils::readParse(buffer, file);

  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;

  int score_p1 = 0;
  int score_p2 = 0;
  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    score_p1 += score_map_p1.at(line_sv[0] * line_sv[2]);
    score_p2 += score_map_p2.at(line_sv[0] * line_sv[2]);
  }
  std::cout << "P1: " << score_p1 << "\n";
  std::cout << "P2: " << score_p2 << "\n";
}

} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 2---\n";
  utils::MicroSecondTimer ms_timer;
  day2(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "us\n\n";
};
