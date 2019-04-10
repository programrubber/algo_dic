#include <iostream>
#include <queue>
#define SIZE 1000
using namespace std;

int V, E;
int visited[SIZE]; // 방문 정보
int G[SIZE][SIZE];  // 인접 행렬
int D[SIZE],P[SIZE]; //D: 시작점에서 정점까지 거리,P: 최단 경로
int Q[SIZE], front, rear; //큐
class Edge {
public:
  int from, to;
  Edge(int from, int to) {
    this->from = from;
    this->to = to;
  }
};

int bfs (int start) {
  queue<int> q;
  visited[start] = 1;
  q.push(start);
  P[start] = start;
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    cout<<v<<" ";
    for(int i=1; i<=V; i++) {
      if (visited[i] == 0 && G[v][i]) {
        q.push(i);
        visited[i] = true;
        D[i] = D[v] + 1;
        P[i] = v;
      }
    }
  }
  printf("\n");
  for(int i=1; i<=V; i++) {
    cout<<"Queue#"<<i<<" :"<<"거리: "<<D[i]<<", 루트: "<<P[i]<<endl;
  }
}

int main() {
  // Test Case 1
  Edge edges[10] = {{1,2},{1,3},{2,4},{2,5},{3,6},
    {5,6},{4,7},{5,7},{6,8},{7,8}};
  int edgesSize = sizeof(edges) / sizeof(*edges);

  V = 8, E = 10; // 정점 수 , 간선 수 세팅
  for(int i=0; i<edgesSize; i++) {
    int from = edges[i].from;
    int to = edges[i].to;
    // 무지향
    G[from][to] = 1;
    G[to][from] = 1;
  }
  bfs(1);
  return 0;
}
