#ifndef GRAPH_H
#define GRAPH_H
#include <cmath>
#include <functional>
#include <unordered_map>
namespace utils
{

struct Point2D
{
  int x{0};
  int y{0};

  auto operator<=>(const Point2D&) const = default;
  Point2D operator+(const Point2D& other) const { return {x + other.x, y + other.y}; }
  Point2D operator-(const Point2D& other) const { return {x - other.x, y - other.y}; }
  Point2D& operator+=(const Point2D& other)
  {
    x += other.x;
    y += other.y;
    return *this;
  }

  Point2D& operator-=(const Point2D& other)
  {
    x -= other.x;
    y -= other.y;
    return *this;
  }
  Point2D operator-() const { return {-x, -y}; }

  int manhattanDistance(const Point2D& other) const
  {
    return std::abs(x - other.x) + std::abs(y - other.y);
  }

  double euclideanDistance(const Point2D& other) const
  {
    int dx = x - other.x;
    int dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
  }
};
template <typename T>
int sgn(T val)
{
  return (T(0) < val) - (val < T(0));
}

constexpr int manhattanDistance(const Point2D& p1, const Point2D& p2)
{
  return std::abs(p1.x - p2.x) + std::abs(p1.y - p2.y);
}

constexpr double euclideanDistance(const Point2D& p1, const Point2D& p2)
{
  int dx = p1.x - p2.x;
  int dy = p1.y - p2.y;
  return std::sqrt(dx * dx + dy * dy);
}

constexpr int euclideanDistanceSquared(const Point2D& p1, const Point2D& p2)
{
  int dx = p1.x - p2.x;
  int dy = p1.y - p2.y;
  return dx * dx + dy * dy;
}

struct Point2DHash
{
  std::size_t operator()(const Point2D& p) const noexcept
  {
    return std::hash<int>{}(p.x) ^ std::hash<int>{}(p.y);
  }
};

template <typename Graph, typename Idx, typename IdxHash>
size_t dijkstra(const Graph& graph, const Idx& start, const Idx& end,
                std::function<std::vector<Idx>(const Graph&, const Idx&)> gen_neighbors)
{
  std::unordered_map<Idx, size_t, IdxHash> dist;
  std::unordered_map<Idx, Idx, IdxHash> prev;
  std::unordered_map<Idx, bool, IdxHash> visited;
  std::unordered_map<Idx, size_t, IdxHash> priority_queue;

  dist[start] = 0;
  priority_queue[start] = 0;

  while (!priority_queue.empty())
  {
    auto [u, _] = *priority_queue.begin();
    priority_queue.erase(priority_queue.begin());

    if (u == end)
    {
      break;
    }

    visited[u] = true;

    for (auto v : gen_neighbors(graph, u))
    {
      if (visited[v])
      {
        continue;
      }

      size_t alt = dist[u] + 1;
      if (dist.find(v) == dist.end() || alt < dist[v])
      {
        dist[v] = alt;
        prev[v] = u;
        priority_queue[v] = alt;
      }
    }
  }

  size_t num_steps = 0;
  auto curr = end;
  while (curr != start)
  {
    curr = prev[curr];
    ++num_steps;
  }

  return num_steps;
}

} // namespace utils
#endif // GRAPH_H