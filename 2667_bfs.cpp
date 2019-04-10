/*
bfs 변형 문제
http://www.algocoding.net/graph/traversal/advance.html
https://www.acmicpc.net/problem/2667
dfs 관련 참고: https://blockdmask.tistory.com/175
*/
#include "stdio.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define SIZE 25

using namespace std;

int MAP[SIZE][SIZE];
int visited[SIZE][SIZE];
int N;
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

bool isInside(int a, int b) {
  return (a>=0 && a<N) && (b>=0 && b<N);
}

int bfs(int x, int y) {
  int count = 0;
  queue<int> qx;
  queue<int> qy;
  if (MAP[x][y] == 0 || visited[x][y] == 1) {
    return 0;
  }
  qx.push(x);
  qy.push(y);
  visited[x][y] = 1;
  count++;
  while(!qx.empty()) {
    int x = qx.front(); qx.pop();
    int y = qy.front(); qy.pop();
    for(int i=0;i<4;i++){
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (!isInside(nx, ny)) {
        continue;
      }
      if(visited[nx][ny] == 0 && MAP[nx][ny] == 1) {
        visited[nx][ny] = 1;
        count++;
        qx.push(nx);
        qy.push(ny);
      }
    }
  }
  return count;
}

int main () {
  // 입력 부
  cin>>N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      scanf("%1d", &MAP[i][j]);
    }
  }

 //Test Case1
  // N = 7;
  // int G[N][N] = {
  //   {0,1,1,0,1,0,0},
  //   {0,1,1,0,1,0,1},
  //   {1,1,1,0,1,0,1},
  //   {0,0,0,0,1,1,1},
  //   {0,1,0,0,0,0,0},
  //   {0,1,1,1,1,1,0},
  //   {0,1,1,1,0,0,0}
  // };
  // for(int i=0; i<N; i++){
  //   for(int j=0; j<N; j++) {
  //     MAP[i][j] = G[i][j];
  //   }
  // }
  //Test Case1 End
  vector<int> arr;

  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      int c = bfs(i,j);
      if (c != 0) {
        arr.push_back(c);
      }
    }
  }
  int t = arr.size();
  cout<<t<<endl; // 총 단지 수
  // sort
  sort(arr.begin(), arr.end()); // 오름차순 정렬
  // sort(arr.begin(), arr.end(), greater<int>()); // 내림차순 정렬
  for(int i=0; i < t; i++){
    if (i == (t-1)) {
      cout<<arr[i];
    } else {
      cout<<arr[i]<<endl;
    }
  }
}
