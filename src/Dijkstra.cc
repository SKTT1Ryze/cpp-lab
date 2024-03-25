#include "../include/Dijkstra.hpp"

#include <algorithm>
#include <cassert>
#include <unordered_set>

using namespace std;

Graph::Graph(const vector<tuple<int, int, int>>& edges) {
  for (const auto& [node1, node2, weight] : edges) {
    auto sharedNode1 = make_shared<GraphNode>(node1);
    auto sharedNode2 = make_shared<GraphNode>(node2);
    this->edges[node1].push_back(GraphEdge(sharedNode2, weight));
    this->edges[node2].push_back(GraphEdge(sharedNode1, weight));
  }
}

int Graph::miniumDistance(int source, int target) {
  int n = this->edges.size();
  unordered_set<int> visited = {};
  vector<int> distance(n, INT_MAX);

  // init
  visited.insert(source);
  distance[source] = 0;
  n--;

  while (n) {
    pair<int, int> next = {-1, INT_MAX};
    for (int node : visited) {
      int currDis = distance[node];
      // neighbor
      for (const auto& edge : this->edges[node]) {
        int neighbor = edge.neighbor->id;
        if (visited.contains(neighbor)) continue;
        int dis = currDis + edge.weight;
        distance[neighbor] = min(distance[neighbor], dis);

        if (distance[neighbor] < next.second) next.first = neighbor;
      }
    }
    // add to path
    visited.insert(next.first);
    n--;
  }

  return distance[target];
}

void executeDijkstra() {
  vector<tuple<int, int, int>> edges = {{0, 1, 2}, {0, 2, 6},  {1, 3, 5},
                                        {2, 3, 8}, {3, 5, 15}, {3, 4, 10},
                                        {4, 5, 6}, {4, 6, 2},  {5, 6, 6}};

  Graph graph(edges);

  auto minDis = graph.miniumDistance(0, 6);

  assert(minDis == 19);
}
