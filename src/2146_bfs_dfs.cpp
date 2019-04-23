/*
다리 만들기
*/
#include <stdio.h>
#include <iostream>
#include <queue>

#define SIZE 100
using namespace std;

int MAP[SIZE][SIZE];
int visited[SIZE][SIZE];
int N;  // 지도의 크기
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

int isInside(int x, int y){
  return (x>=0 && x<N) && (y>=0 && y<N);
}

int bfs(int x, int y) {
  queue<int> qx;
  queue<int> qy;
  int selfLandNum = MAP[y][x];
  int landVisited[N][N];
  int cost[N][N];
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      landVisited[i][j] = 0;
      cost[i][j] = 0;
    }
  }
  qx.push(x);
  qy.push(y);
  landVisited[y][x] = 1;
  while(!qx.empty()) {
    x = qx.front(); qx.pop();
    y = qy.front(); qy.pop();
    if (MAP[y][x] != selfLandNum && MAP[y][x] != 0) {
      break;
    }
    for(int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!isInside(nx, ny)) continue;
      if (MAP[ny][nx] == selfLandNum) continue;
      if (landVisited[ny][nx] == 1) continue;
      landVisited[ny][nx] = 1;
      cost[ny][nx] = cost[y][x] + 1;
      qx.push(nx);
      qy.push(ny);
    }
  }
  // for(int i=0; i<N; i++) {
  //   for(int j=0; j<N; j++){
  //     cout<<cost[i][j];
  //   }
  //   cout<<endl;
  // }
  // cout<<"x: "<<x<<", y: "<<y<<endl;
  return cost[y][x] - 1;
}

void dfs(int x, int y, int landNum) { // 영토 탐색
  visited[y][x] = 1;
  MAP[y][x] = landNum;
  for(int i=0; i<4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (!isInside(nx, ny)){
      continue;
    }
    if (visited[ny][nx] == 0 && MAP[ny][nx] != 0) {
      dfs(nx, ny, landNum);
    }
  }
}

int main () {
  //insert part
  cin>>N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      scanf("%1d", &MAP[i][j]);
    }
  }

  //test case1
  // N = 10;
  // int G[N][N] = {
  //   {1,1,1,0,0,0,0,1,1,1},
  //   {1,1,1,1,0,0,0,0,1,1},
  //   {1,0,1,1,0,0,0,0,1,1},
  //   {0,0,1,1,1,0,0,0,0,1},
  //   {0,0,0,1,0,0,0,0,0,1},
  //   {0,0,0,0,0,0,0,0,0,1},
  //   {0,0,0,0,0,0,0,0,0,0},
  //   {0,0,0,0,1,1,0,0,0,0},
  //   {0,0,0,0,1,1,1,0,0,0},
  //   {0,0,0,0,0,0,0,0,0,0}
  // };
  //inject test case
  // for(int i=0; i<N; i++) {
  //   for(int j=0; j<N; j++) {
  //     MAP[i][j] = G[i][j];
  //   }
  // }

  // 영토 표시
  int cnt = 1; // 영토 번호
  for(int y=0; y<N; y++) {
    for(int x=0; x<N; x++) {
      if (visited[y][x] == 0 && MAP[y][x] != 0) {
        // 바다를 제외한 방문 하지 않은 곳
        cnt++;
        dfs(x, y, cnt);
      }
    }
  }

  // 최저 다리 비용
  int cost = 1000;
  for(int y=0; y<N; y++) {
    for(int x=0; x<N; x++) {
      if (MAP[y][x] == 0) continue; //바다는 스킵
      int tempCost = bfs(x,y);
      if (cost > tempCost && tempCost > 0) {
        cost = tempCost;
      } 
    }
  }
  //check print
  // for(int y=0; y<N; y++) {
  //   for(int x=0; x<N; x++) {
  //     cout<<MAP[y][x]<<" ";
  //   }
  //   cout<<endl;
  // }
  cout<<cost;
}
