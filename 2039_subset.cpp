#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#define SIZE 9

using namespace std;

int P[SIZE]; // 난쟁이 9명
int bits[SIZE];
int isFind = false;

void subset(int k, int n) {
  if (k==n) {
    int cnt = 0;
    vector<int> v;
    for(int i=0; i<n; i++) {
      if (bits[i] == 1) {
        cnt += P[i];
        v.push_back(P[i]);
      }
    }
    int vCnt= v.size();
    if(cnt == 100 && vCnt == 7) {
      sort(v.begin(), v.end());
      for(int i=0; i<vCnt; i++) {
        if (i == (vCnt-1)) {
          cout<<v[i];
        } else {
          cout<<v[i]<<endl;
        }
      }
      isFind = true;
    }
    return;
  }
  if (isFind) return;
  bits[k]=0; subset(k+1, n);
  bits[k]=1; subset(k+1, n);
}

int main () {
  //insert
  for(int i=0; i<9; i++) {
    cin>>P[i];
  }
  //test case1
  // int G[9]={20,7,23,19,10,15,25,8,13};
  //inject test case
  // for(int i=0; i<9; i++) {
  //   P[i] = G[i];
  // }
  //Logic
  subset(0, 9);
  // 모든 경우의수를 통해서 100에 근접한 수를 찾기
  //check print
  // for(int i=0; i<9; i++) {
  //   cout<<P[i]<<endl;
  // }
}
