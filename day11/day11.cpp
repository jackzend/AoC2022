#include <boost/multiprecision/cpp_int.hpp>
#include <utils/basic_timer.h>
#include <utils/constexpr_map.h>
#include <utils/parse.h>
#include <utils/third_party/emhash/hash_set8.hpp>
namespace AoC2022
{
using namespace boost::multiprecision;
constexpr std::string_view input_fp = "/home/jack-slip/AoC2022/input/day11.txt";

struct Monkey
{
  int id;
  std::vector<int64_t> items;
  std::function<void(int64_t&)> op;
  std::function<bool(int64_t)> test_op;
  int true_dest;
  int false_dest;
  size_t inspection_count{0};
};

std::function<void(int64_t&)> makeOp(std::vector<std::string_view>& tokens)
{
  if (tokens[4] == "+")
  {
    // Make a pluser op
    if (tokens[5] != "old")
    {
      int val = utils::stringViewToInt(tokens[5]);
      return [val](int64_t& a) { a += val; };
    }
    return [](int64_t& a) { a += a; };
  }
  else if (tokens[4] == "*")
  {
    // Make a multiplier op
    if (tokens[5] != "old")
    {
      int val = utils::stringViewToInt(tokens[5]);
      return [val](int64_t& a) { a *= val; };
    }
    return [](int64_t& a) { a *= a; };
  }
  else
  {
    std::cout << "Should only be these two ops";
    throw std::runtime_error("Invalid op");
  }
}

std::function<bool(int64_t)> makeTestOp(std::vector<std::string_view>& tokens)
{
  int val = utils::stringViewToInt(tokens[3]);
  return [val](int64_t a) { return a % val == 0; };
}

Monkey makeMonkey(std::string_view line, const char*& start, const char* end)
{
  Monkey monk;
  auto tokens = utils::splitSVPtr(line, " :");
  monk.id = utils::stringViewToInt(tokens[1]);

  line = utils::getLine(start, end);

  tokens = utils::splitSVPtr(line, " ,");
  for (int i = 2; i < tokens.size(); i += 1)
  {
    auto temp = tokens[i];
    monk.items.push_back(static_cast<int64_t>(utils::stringViewToInt(tokens[i])));
  }

  line = utils::getLine(start, end);
  tokens = utils::splitSVPtr(line, " ");
  monk.op = makeOp(tokens);

  line = utils::getLine(start, end);
  tokens = utils::splitSVPtr(line, " ");
  monk.test_op = makeTestOp(tokens);

  line = utils::getLine(start, end);
  tokens = utils::splitSVPtr(line, " ");
  monk.true_dest = utils::stringViewToInt(tokens[5]);

  line = utils::getLine(start, end);
  tokens = utils::splitSVPtr(line, " ");
  monk.false_dest = utils::stringViewToInt(tokens[5]);

  utils::getLine(start, end); // Skip the empty line
  return monk;
}

void day11(const char* fp)
{
  std::vector<char> buffer;
  utils::readParse(buffer, fp);
  const char* line = &buffer[0];
  const char* end = line + buffer.size();

  std::string_view line_sv;
  std::vector<Monkey> monkeys;
  while (!(line_sv = utils::getLine(line, end)).empty())
  {
    monkeys.push_back(makeMonkey(line_sv, line, end));
  }

  for (int i = 0; i < 20; ++i)
  {
    for (int j = 0; j < monkeys.size(); ++j)
    {
      auto& monk = monkeys[j];
      monk.inspection_count += monk.items.size();
      for (int k = 0; k < monk.items.size(); ++k)
      {
        int64_t& item = monk.items[k];
        monk.op(item);
        item /= 3;
        if (monk.test_op(item))
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

  std::cout << "Inspection Count 1 " << monkeys[monkeys.size() - 1].inspection_count << "\n";
  std::cout << "Inspection Count 2 " << monkeys[monkeys.size() - 2].inspection_count << "\n";
  std::cout << "P1: "
            << monkeys[monkeys.size() - 1].inspection_count *
                   monkeys[monkeys.size() - 2].inspection_count
            << "\n";
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