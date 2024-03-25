#include <climits>
#include <memory>
#include <tuple>
#include <unordered_map>
#include <vector>

struct GraphNode {
  int id;

  GraphNode(int id) : id(id) {}
};

struct GraphEdge {
  std::shared_ptr<GraphNode> neighbor;
  int weight;

  GraphEdge(std::shared_ptr<GraphNode> neighbor, int weight)
      : neighbor(neighbor), weight(weight) {}
};

class Graph {
 private:
  std::unordered_map<int, std::vector<GraphEdge>> edges;

 public:
  Graph(const std::vector<std::tuple<int, int, int>>& edges);
  int miniumDistance(int source, int target);
};

void executeDijkstra();
