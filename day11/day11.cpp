#include <numeric>
#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>

#include <memory>
namespace AoC2022
{
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day11.txt";

enum class OP
{
  PLUS,
  DOUBLE,
  MULTIPLY,
  SQUARE
};

struct Monkey
{
  int test_val;
  std::vector<int64_t> items;
  OP op;

  int op_val{0};

  int true_dest;
  int false_dest;
  size_t inspection_count{0};
};

void getOp(std::vector<std::string_view>& tokens, Monkey& m)
{
  if (tokens[4] == "+")
  {
    // Make a pluser op
    if (tokens[5] != "old")
    {
      m.op = OP::PLUS;
      m.op_val = utils::stringViewToInt(tokens[5]);
      return;
    }
    m.op = OP::DOUBLE;
    return;
  }
  else if (tokens[4] == "*")
  {
    // Make a multiplier op
    if (tokens[5] != "old")
    {
      m.op = OP::MULTIPLY;
      m.op_val = utils::stringViewToInt(tokens[5]);
      return;
    }
    m.op = OP::SQUARE;
    return;
  }
  else
  {
    std::cout << "Should only be these two ops";
    throw std::runtime_error("Invalid op");
  }
}

Monkey makeMonkey(std::string_view line, const char*& start, const char* end)
{
  Monkey monk;
  line = utils::getLine(start, end);
  auto tokens = utils::splitSVPtr(line, " ,");

  for (int i = 2; i < tokens.size(); i += 1)
  {
    monk.items.push_back(static_cast<int64_t>(utils::stringViewToInt(tokens[i])));
  }

  line = utils::getLine(start, end);
  tokens = utils::splitSVPtr(line, " ");
  getOp(tokens, monk);

  line = utils::getLine(start, end);
  tokens = utils::splitSVPtr(line, " ");
  monk.test_val = utils::stringViewToInt(tokens[3]);

  line = utils::getLine(start, end);
  tokens = utils::splitSVPtr(line, " ");
  monk.true_dest = utils::stringViewToInt(tokens[5]);

  line = utils::getLine(start, end);
  tokens = utils::splitSVPtr(line, " ");
  monk.false_dest = utils::stringViewToInt(tokens[5]);

  utils::getLine(start, end); // Skip the empty line
  return monk;
}

inline void doOp(int64_t& item, OP op, int op_val)
{
  switch (op)
  {
  case OP::PLUS:
    item += op_val;
    break;
  case OP::DOUBLE:
    item *= 2;
    break;
  case OP::MULTIPLY:
    item *= op_val;
    break;
  case OP::SQUARE:
    item *= item;
    break;
  }
}

void day11(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;
  std::vector<Monkey> monkeys;
  std::vector<Monkey> monkeys2;

  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    monkeys.push_back(makeMonkey(line_sv, line, end));
  }

  monkeys2 = monkeys;

  int64_t special_value =
      std::accumulate(monkeys.begin(), monkeys.end(), 1,
                      [](int64_t a, const Monkey& curr) { return a * curr.test_val; });

  for (int i = 0; i < 20; ++i)
  {
    for (int j = 0; j < monkeys.size(); ++j)
    {
      auto& monk = monkeys[j];
      monk.inspection_count += monk.items.size();
      for (int k = 0; k < monk.items.size(); ++k)
      {
        auto& item = monk.items[k];

        doOp(item, monk.op, monk.op_val);

        item /= 3;

        if (item % monk.test_val == 0)
        {
          monkeys[monk.true_dest].items.push_back(item);
        }
        else
        {
          monkeys[monk.false_dest].items.push_back(item);
        }
      }
      monk.items.clear();
    }
  }

  std::sort(monkeys.begin(), monkeys.end(),
            [](const Monkey& a, const Monkey& b)
            { return a.inspection_count < b.inspection_count; });

  std::cout << "P1: "
            << monkeys[monkeys.size() - 1].inspection_count *
                   monkeys[monkeys.size() - 2].inspection_count
            << "\n"; // 76728

  for (int i = 0; i < 10000; ++i)
  {
    for (int j = 0; j < monkeys2.size(); ++j)
    {
      auto& monk = monkeys2[j];
      monk.inspection_count += monk.items.size();
      for (int k = 0; k < monk.items.size(); ++k)
      {
        auto& item = monk.items[k];
        doOp(item, monk.op, monk.op_val);
        if (item > special_value)
        {
          item = item % special_value;
        }

        if (item % monk.test_val == 0)
        {
          monkeys2[monk.true_dest].items.push_back(item);
        }
        else
        {
          monkeys2[monk.false_dest].items.push_back(item);
        }
      }
      monk.items.clear();
    }
  }

  std::sort(monkeys2.begin(), monkeys2.end(),
            [](const Monkey& a, const Monkey& b)
            { return a.inspection_count < b.inspection_count; });

  std::cout << "P2: "
            << monkeys2[monkeys2.size() - 1].inspection_count *
                   monkeys2[monkeys2.size() - 2].inspection_count
            << "\n";

  // 21553910156
}
} // namespace AoC2022

using namespace AoC2022;
int main()
{
  std::cout << "---Day 11---\n";
  utils::MicroSecondTimer ms_timer;
  day11(input_fp.begin());
  float elapsed = ms_timer.getElapsed();
  std::cout << "Elapsed: " << elapsed << "us\n\n";
}