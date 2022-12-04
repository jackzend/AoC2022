#include <bitset>
#include <cctype>
#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>
namespace AoC2022
{

constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day3.txt";

constexpr char getIdx(const char c)
{
  if (c - 'a' >= 0 and c - 'a' < 26)
  {
    return c - 'a';
  }
  else
  {
    return c - 'A' + 26;
  }
}

constexpr char getPriority(const char c) { return getIdx(c) + 1; }

constexpr int getIdxOfFirstBit(const std::bitset<52>& bs)
{
  for (int i = 0; i < 52; ++i)
  {
    if (bs[i])
    {
      return i;
    }
  }
  return -1;
}

void day3(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view rucksack;

  const char* beg;
  const char* mid;
  int sum = 0;

  std::bitset<52> seen;

  std::bitset<52> seen1;
  std::bitset<52> seen2;
  std::bitset<52> seen3;

  int sum_p2 = 0;
  int elf_count = 0;
  while (!(rucksack = utils::getLine(line, end)).empty())
  {
    // part 1
    beg = rucksack.begin();
    mid = beg;
    std::advance(mid, rucksack.size() / 2);

    while (beg < mid)
    {
      seen.set(getIdx(*beg));
      ++beg;
    }
    while (mid < rucksack.end())
    {
      if (seen[getIdx(*mid)])
      {
        sum += getPriority(*mid);
        break;
      }
      ++mid;
    }
    seen.reset();

    // part 2
    beg = rucksack.begin();

    auto& curr_bs = elf_count == 0 ? seen1 : elf_count == 1 ? seen2 : seen3;
    while (beg < rucksack.end())
    {
      curr_bs.set(getIdx(*beg));
      ++beg;
    }
    ++elf_count;
    if (elf_count == 3)
    {
      seen1 &= seen2;
      seen1 &= seen3;
      sum_p2 += getIdxOfFirstBit(seen1) + 1;

      seen1.reset();
      seen2.reset();
      seen3.reset();
      elf_count = 0;
    }
  }
  std::cout << "P1: " << sum << "\n";
  std::cout << "P2: " << sum_p2 << "\n";
}

} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 3---\n";
  utils::MicroSecondTimer ms_timer;
  day3(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "us\n\n";
}
