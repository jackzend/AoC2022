#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>

#include <memory>
#include <stack>
#include <unordered_map>

namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day7.txt";

inline bool isNewDir(std::vector<std::string_view>& tokens)
{
  return tokens[1] == "cd" and tokens[2] != "..";
}

void day7(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;

  std::stack<size_t> dir_stack;
  size_t num_under = 0;

  std::vector<size_t> dir_counts;

  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    auto tokens = utils::splitSVPtr(line_sv, " ");

    if (tokens[0] == "$")
    {
      if (isNewDir(tokens))
      {
        dir_stack.push(0);
        utils::getLine(line, end);
      }
      else
      {
        auto top = dir_stack.top();
        dir_stack.pop();
        dir_stack.top() += top;
        if (top <= 100000)
          num_under += top;
        dir_counts.push_back(top);
      }
    }
    else
    {
      if (tokens[0] == "dir")
        continue;
      else
      {
        dir_stack.top() += utils::stringViewToInt(tokens[0]);
      }
    }
  }

  while (!dir_stack.empty())
  {
    auto top = dir_stack.top();
    dir_stack.pop();
    dir_stack.top() += top;
    if (top <= 100000)
      num_under += top;
    dir_counts.push_back(top);
  }

  size_t target = 70000000 - dir_counts.back();

  auto part_it = std::partition(dir_counts.begin(), dir_counts.end(),
                                [target](auto& v) { return v + target >= 30000000; });

  std::cout << "P1: " << num_under << "\n";
  std::cout << "P2: " << *std::min_element(dir_counts.begin(), part_it) << "\n";
}
} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 7---\n";
  utils::MicroSecondTimer ms_timer;
  day7(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "us\n\n";
}