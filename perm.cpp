// 요소들의 순서대로 선택: http://www.algocoding.net/design/search/permutation.html
#include <iostream>
#define SIZE 10000
using namespace std;

int arr[SIZE]; //요소들을 저장
int sel[SIZE]; //순열 저장
bool visited[SIZE] = {false,}; //선택된 요소의 수
int N;


void print_arr () {
  cout << "result: ";
  for(int i=0; i<N; i++) {
    if (i == N-1) {
      cout << sel[i] << endl;
    } else {
      cout << sel[i] << ", ";
    }
  }
}


void perm(int n, int k) { // k: 선택한 요소의 수
  if (k == n) {
    print_arr();
    return ;
  }
  for(int i = 0; i < n; i++) {
    if (visited[i]) continue;
    visited[i] = true;
    sel[k] = arr[i];
    perm(n, k+1);
    visited[i] = false;
  }
}

int main () {
  N = 4;
  for(int i = 0; i < N; i++) {
    arr[i] = i+1;
  }
  perm(N, 0);
  return 0;
}
