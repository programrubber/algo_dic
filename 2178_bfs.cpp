/*
미로 탐색
https://www.acmicpc.net/problem/2178
*/
#include <stdio.h>
#include <iostream>
#include <queue>
#define SIZE 100

using namespace std;

int MAP[SIZE][SIZE];
int N,M;
int visited[SIZE][SIZE];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

bool isInside(int x, int y) {
  // cout << "x: "<< x << ",y: " << y << (((x>=0 && x<M) && (y>=0 && y<N)) ? "true" : "false") << endl;
  return (x>=0 && x<M) && (y>=0 && y<N);
}

int bfs(int x, int y) {  
  int dis[N][M];
  dis[0][0] = 1;
  queue<int> qx;
  queue<int> qy;
  qx.push(x);
  qy.push(y);
  visited[y][x] = 1;
  while(!qx.empty()) {
    x = qx.front(); qx.pop();
    y = qy.front(); qy.pop();
    // cout << "x: "<< x << ",y: " << y  << endl;
    if (N == (y-1) && M == (x-1)) {
      break;
    }
    for(int i=0; i<4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!isInside(nx, ny)) {
        continue;
      }
      if (visited[ny][nx]==0 && MAP[ny][nx]==1) {
        visited[ny][nx]=1;
        qx.push(nx);
        qy.push(ny);
        dis[ny][nx] = dis[y][x] + 1;
      }
    }
  }
  return dis[N-1][M-1];
}

int main () {
  cin>>N>>M;
  for(int i=0; i<N; i++) {
    for(int j=0; j<M; j++) {
      scanf("%1d", &MAP[i][j]);
    }
  }

  // testCase1
  // N = 4, M = 6;
  // int G[N][M] = {
  //   {1,0,1,1,1,1},
  //   {1,0,1,0,1,0},
  //   {1,0,1,0,1,1},
  //   {1,1,1,0,1,1}
  // };
  // testCase inject
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<M; j++){
  //     MAP[i][j] = G[i][j];
  //   }
  // }

  //input Check
  // cout<<endl;
  // cout<<N<<","<<M;
  // cout<<endl;
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<M; j++){
  //     cout<<MAP[i][j]<<" ";
  //   }
  //   cout<<endl;
  // }

  // Logic
  int c = bfs(0, 0);
  cout<<c;
}
