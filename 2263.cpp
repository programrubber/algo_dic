#include <stdio.h>
#include <iostream>
#define SIZE 100001

using namespace std;

int N;

int InOrder[SIZE]; // 중위, LPR
int PostOrder[SIZE]; // 후위, LRP

void injectOrder(int inS, int inE, int postS, int postE) {
  int v = PostOrder[postE];
  int vIndex = -1;
  int leftCnt=0;
  int rightCnt=0;
  for(int i=inS; i<=inE; i++) {
    if (InOrder[i] == v) {
      vIndex = i;
    } else if (vIndex == -1) {
      leftCnt++;
    } else {
      rightCnt++;
    }
  }
  cout<<v<<" ";
  if (leftCnt>0) {
    injectOrder(inS, vIndex-1, postS, postS+leftCnt-1);
  }
  if (rightCnt>0) {
    injectOrder(vIndex+1, inE, postS+leftCnt, postE-1);
  }
}

int main () {
  //input
  cin>>N;
  for(int i=1; i <= N; i++) {
    scanf("%d", &InOrder[i]);
  }
  for(int i=1; i <= N; i++) {
    scanf("%d", &PostOrder[i]);
  }
  //testcase1
  // N = 13;
  // int inN[N+1] =   {0,8,4,2,9,5,1,13,10,6,11,3,12,7};
  // int postN[N+1] = {0,8,4,9,5,2,13,10,11,6,12,7,3,1};
  // for(int i=1; i<= N; i++){
  //   InOrder[i] = inN[i];
  //   PostOrder[i] = postN[i];
  // }

  injectOrder(1, N, 1, N);
}
