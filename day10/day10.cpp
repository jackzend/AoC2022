#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>
namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day10.txt";

void drawPixel(std::vector<char>& screen, int pix_idx, int cursor_pos)
{
  int real_idx = pix_idx % 40;
  if (cursor_pos == real_idx or cursor_pos - 1 == real_idx or cursor_pos + 1 == real_idx)
    screen[pix_idx] = '#';
}

void day10(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;
  size_t cycle = 0;
  long X = 1;

  std::vector<std::string_view> tokens;
  tokens.resize(2);

  int signal_strength = 0;

  std::vector<char> screen(240UL, '.');

  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    if (line_sv[0] == 'n')
    {
      ++cycle;
      // Start of the cycle
      if (cycle == 20 or cycle % 40 == 20)
        signal_strength += X * cycle;

      // draw pixel
      drawPixel(screen, cycle - 1, X);

      continue;
    }
    utils::splitSVPtrInPlaceNoCheck(line_sv, " ", tokens);
    ++cycle;
    if (cycle == 20 or cycle % 40 == 20)
      signal_strength += X * cycle;
    drawPixel(screen, cycle - 1, X);
    ++cycle;
    if (cycle == 20 or cycle % 40 == 20)
      signal_strength += X * cycle;
    drawPixel(screen, cycle - 1, X);
    X += utils::stringViewToInt(tokens[1]);
  }

  std::cout << "P1: " << signal_strength << '\n';
  std::cout << "P2: \n";
  for (int i = 0; i < 6; ++i)
  {
    for (int j = 0; j < 40; ++j)
    {
      std::cout << screen[i * 40 + j];
    }
    std::cout << '\n';
  }
}
} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 10---\n";
  utils::MicroSecondTimer ms_timer;
  day10(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "us\n\n";
}