#include <deque>
#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>
namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day5.txt";
// constexpr std::string_view input_fp = "/home/jack-slip/Downloads/aoc_2022_day05_large_input.txt";

void day5(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;

  std::vector<std::deque<char>> stack_arr{9UL};
  //   for (int i = 0; i < 8; ++i)
  //   {
  //     line_sv = utils::getLine(line, end);
  //     static constexpr size_t end_idx = 8 * 4 + 2;
  //     for (size_t idx = 1; idx < end_idx; idx += 4)
  //     {
  //       size_t ins_idx = idx / 4;
  //       char temp = line_sv[idx];
  //       if (utils::isAlpha(temp))
  //         stack_arr[ins_idx].push_front(temp);
  //     }
  //   }

  while ((line_sv = utils::getLine(line, end))[1] != '1')
  {
    static constexpr size_t end_idx = 8 * 4 + 2;
    for (size_t idx = 1; idx < end_idx; idx += 4)
    {
      size_t ins_idx = idx / 4;
      char temp = line_sv[idx];
      if (utils::isAlpha(temp))
        stack_arr[ins_idx].push_front(temp);
    }
  }

  std::vector<std::deque<char>> stack_arr_p2;
  std::copy(stack_arr.begin(), stack_arr.end(), std::back_inserter(stack_arr_p2));

  // skip past 2 junk lines
  //   utils::getLine(line, end);
  utils::getLine(line, end);

  std::vector<std::string_view> sv_vec;
  sv_vec.resize(6);

  int num_to_move, id_from, id_to;
  char temp;
  char temp2;
  std::vector<char> temp_vec_p2;

  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    static constexpr std::string_view delim{" "};
    utils::splitSVPtrInPlaceNoCheck(line_sv, delim, sv_vec);

    num_to_move = utils::stringViewToInt(sv_vec[1]);
    id_from = utils::stringViewToInt(sv_vec[3]) - 1;
    id_to = utils::stringViewToInt(sv_vec[5]) - 1;

    temp_vec_p2.resize(num_to_move);

    for (int i = 0; i < num_to_move; ++i)
    {
      temp = stack_arr[id_from].back();
      stack_arr[id_from].pop_back();
      stack_arr[id_to].push_back(temp);

      temp2 = stack_arr_p2[id_from].back();
      stack_arr_p2[id_from].pop_back();
      temp_vec_p2[i] = temp2;
    }
    std::for_each(temp_vec_p2.rbegin(), temp_vec_p2.rend(),
                  [&stack_arr_p2, id_to](const char c) { stack_arr_p2[id_to].push_back(c); });
  }
  std::cout << "P1: ";
  for (int i = 0; i < 9; ++i)
  {
    std::cout << stack_arr[i].back();
  }
  std::cout << "\n";

  std::cout << "P2: ";
  for (int i = 0; i < 9; ++i)
  {
    std::cout << stack_arr_p2[i].back();
  }
  std::cout << "\n";
}
} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 5---\n";
  utils::SecondTimer ms_timer;
  day5(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "s\n\n";
}