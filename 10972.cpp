// pandit 알고리즘을 적용
#include <stdio.h>
#include <iostream>
#define SIZE 10000
using namespace std;

int arr[SIZE];
int N;
int sel[SIZE];
bool isFind = false;

void print_arr() {
  if (isFind == false) {
    cout << -1;
    return;
  }
  for(int i=0; i<N; i++) {
    if (i == N-1) {
      cout << sel[i];
    } else {
      cout << sel[i] << " ";
    }
  }
  cout << endl;
}

void swap(int &a, int &b) {
  int temp = a; a = b; b = temp;
}

void pandit() {
  if (sel[N-2] < sel[N-1]) {
    swap(sel[N-2], sel[N-1]);
    isFind = true;
    return ;
  }
  int i = -1, j = -1;
  for(int k = N; k > -1; k--) {
    if (sel[k] < sel[k+1]) {
      i = k;
      break;
    }
  }
  for(int k = 0; k < N; k++) {
    if ((sel[i] + 1) == sel[k]) {
      j = k;
      break;
    }
  }
  if (i == -1 || j == -1) return;
  isFind = true;
  swap(sel[i], sel[j]);
  int tempArr[N];
  int index = 0;
  for(int k = 0; k <= i; k++) {
    tempArr[k] = sel[k];
    index = k;
  }
  for(int k = N-1; i < k; k--) {
    tempArr[++index] = sel[k];
  }
  for(int k=0; k<N; k++) {
    sel[k] = tempArr[k];
  }
}

int main() {
  cin>>N;
  for(int i=0; i<N; i++) {
    scanf("%d", &sel[i]);
  }
  pandit();
  print_arr();
  return 0;
}
