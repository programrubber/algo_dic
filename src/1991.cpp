#include <stdio.h>
#include <iostream>
#define SIZE 26

using namespace std;

char Tree[SIZE][3];
int N;

char Value[SIZE];
char Left[SIZE];
char Right[SIZE];

void preOrder(char v) {
  if (v == '.') return;
  char l, r;
  for(int i=0; i<N; i++) {
    if(Value[i] == v) {
      l = Left[i];
      r = Right[i];
      break;
    }
  }
  cout<<v;
  preOrder(l);
  preOrder(r);
}
void inOrder(char v) {
  if (v == '.') return;
  char l, r;
  for(int i=0; i<N; i++) {
    if(Value[i] == v) {
      l = Left[i];
      r = Right[i];
      break;
    }
  }
  inOrder(l);
  cout<<v;
  inOrder(r);
}
void postOrder(char v) {
  if (v == '.') return;
  char l, r;
  for(int i=0; i<N; i++) {
    if(Value[i] == v) {
      l = Left[i];
      r = Right[i];
      break;
    }
  }
  postOrder(l);
  postOrder(r);
  cout<<v;
}

int main() {
  // input
  cin>>N;
  for(int i=0; i<N; i++) {
    for(int j=0; j<3; j++) {
      scanf("%s", &Tree[i][j]);
    }
  }
  //testcase
  // N = 7;
  // char temp[N][3] = {
  //   {'A', 'B', 'C'},
  //   {'B', 'D', '.'},
  //   {'C', 'E', 'F'},
  //   {'E', '.', '.'},
  //   {'F', '.', 'G'},
  //   {'D', '.', '.'},
  //   {'G', '.', '.'}
  // };
  // for(int i=0; i<N; i++) {
  //   for(int j=0; j<3; j++) {
  //     Tree[i][j] = temp[i][j];
  //   }
  // }

  //inject
  for(int i=0; i<N; i++) {
    Value[i] = Tree[i][0];
    Left[i] = Tree[i][1];
    Right[i] = Tree[i][2];
  }
  //print
  preOrder('A');
  cout<<endl;
  inOrder('A');
  cout<<endl;
  postOrder('A');
}
