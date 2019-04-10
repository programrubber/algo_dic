// 부분집합 알고리즘
#include <stdio.h>
#include <iostream>

using namespace std;

char arr[] = "ABCD";
int bits[4];
void subset(int k, int n) { //최초 k, n=4 호출
  if(k == n) {
    for(int i=0; i<n; i++) {
      if (bits[i]) cout<<arr[i];
    }
    cout << endl;
    return;
  }
  bits[k]=1; subset(k+1, n);
  bits[k]=0; subset(k+1, n);
}

int main() {
  subset(0, 4);
  return 0;
}
