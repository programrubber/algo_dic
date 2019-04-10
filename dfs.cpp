#include <iostream>
#include <queue>
#define SIZE 100

using namespace std;

int G[SIZE][SIZE]; // 인접 행렬
int visited[SIZE]; // 방문정보
int V, E; // 정점 수, 간선 수

class Edge {
public:
  int from, to;
  Edge(int from, int to) {
    this->from = from;
    this->to = to;
  }
};

void dfs(int v) {
  visited[v] = 1;
  cout<<v<<" ";
  for(int i = 1; i <= V; i++) {
    if (visited[i] == 0 && G[v][i]) {
      dfs(i);
    }
  }
}

int main () {
  // Test Case 1
  Edge edges[10] = {{1,2},{1,3},{2,4},{2,5},{3,6},
    {5,6},{4,7},{5,7},{6,8},{7,8}};
  V = 8, E = 10;
  int edgesLength = sizeof(edges) / sizeof(*edges);
  for(int i = 0; i<edgesLength; i++) {
    int from = edges[i].from;
    int to = edges[i].to;
    G[from][to] = 1;
    G[to][from] = 1;
  }
  dfs(1);
}
