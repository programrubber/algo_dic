// 두 요소의 교환으로 생성되는 순열: http://www.algocoding.net/design/search/permutation.html
#include <iostream>
using namespace std;

char arr[] = "ABCDE";
char sel[5];
int cnt;
inline void swap(char & a, char & b);
void print_arr();

void perm (int depth, int k) {
  if (depth == k) {
    print_arr();
    return;
  }
  for (int i = depth; i <= k; i++) {
    // cout<< "(" << depth << ", " << i << ")" << k << endl;
    swap(arr[depth], arr[i]);
    perm(depth+1, k);
    swap(arr[depth], arr[i]);
  }
}

int main () {
  perm(0, 4);
  return 0;
}

inline void swap(char & a, char & b) {
  int tmp = a; a = b; b = tmp;
}

void print_arr(){
  printf("%2d> ", ++cnt);
  for (int i=0; i<5; i++) {
    printf("%c", arr[i]);
  }
  printf("\n");
}
