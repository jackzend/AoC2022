#ifndef CONSTEXPR_MAP
#define CONSTEXPR_MAP
#include <algorithm>
#include <array>

namespace utils
{
template <typename Key, typename Value, std::size_t Size>
struct Map
{
  std::array<std::pair<Key, Value>, Size> data;

  [[nodiscard]] constexpr Value at(const Key& key) const
  {
    const auto itr =
        std::find_if(begin(data), end(data), [&key](const auto& v) { return v.first == key; });
    if (itr != end(data))
    {
      return itr->second;
    }
    else
    {
      throw std::range_error("Not Found");
    }
  }
};
} // namespace utils

// example of using this to generate constexpr map
// static constexpr auto prio_arr = []()
// {
//   std::array<std::pair<char, int>, 52UL> ret{};
//   for (char c = 'a'; c <= 'z'; ++c)
//   {
//     ret[getIdx(c)].first = c;
//     ret[getIdx(c)].second = getPriority(c);
//   }
//   for (char c = 'A'; c <= 'Z'; ++c)
//   {
//     ret[getIdx(c)].first = c;
//     ret[getIdx(c)].second = getPriority(c);
//   }
//   return ret;
// }();

// static constexpr auto prio_map = utils::Map<char, int, prio_arr.size()>{{prio_arr}};

#endif