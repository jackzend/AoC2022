#include <iomanip>
#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>

#include <ranges>
namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day4.txt";

void day4(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;
  constexpr std::string_view delim1{",-"};

  int r1_beg, r1_end, r2_beg, r2_end;

  int sum_p1 = 0;
  int sum_p2 = 0;

  std::vector<std::string_view> both_ranges;
  both_ranges.resize(4UL);
  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    utils::splitSVPtrInPlaceNoCheck(line_sv, delim1, both_ranges);

    r1_beg = utils::stringViewToInt(both_ranges[0]);
    r1_end = utils::stringViewToInt(both_ranges[1]);

    r2_beg = utils::stringViewToInt(both_ranges[2]);
    r2_end = utils::stringViewToInt(both_ranges[3]);

    // part1
    bool check1 = r1_beg <= r2_beg and r1_end >= r2_end;
    bool check2 = r2_beg <= r1_beg and r2_end >= r1_end;
    if (check1 or check2)
      ++sum_p1;

    // part 2
    bool check3 = r2_beg >= r1_beg and r2_beg <= r1_end;
    bool check4 = r2_end >= r1_beg and r2_end <= r1_end;
    if (check1 or check2 or check3 or check4)
      ++sum_p2;
  }
  std::cout << "P1: " << sum_p1 << "\n";
  std::cout << "P2: " << sum_p2 << "\n";
}
} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 4---\n";
  utils::MicroSecondTimer ms_timer;
  day4(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "us\n\n";
}