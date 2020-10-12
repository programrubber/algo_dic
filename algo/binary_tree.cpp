#include "iostream"
#define SIZE 1000

using namespace std;

int N = 7;
char arr[SIZE][3]; // 0번째: parent, 1번째: left, 2번째: right

void preOrder (char parent) {
    char left = '.', right = '.';
    for (int i=0; i<N; i++) {
        if (arr[i][0] == parent) {
            left = arr[i][1];
            right = arr[i][2];
        }
    }
    if (parent != '.') cout << parent;
    if (left != '.') preOrder(left);
    if (right != '.') preOrder(right);
}

void inOrder (char parent) {
    char left = '.', right = '.';
    for (int i=0; i<N; i++) {
        if (arr[i][0] == parent) {
            left = arr[i][1];
            right = arr[i][2];
        }
    }
    if (left != '.') inOrder(left);
    if (parent != '.') cout << parent;
    if (right != '.') inOrder(right);
}

void postOrder (char parent) {
    char left = '.', right = '.';
    for (int i=0; i<N; i++) {
        if (arr[i][0] == parent) {
            left = arr[i][1];
            right = arr[i][2];
        }
    }
    if (left != '.') postOrder(left);
    if (right != '.') postOrder(right);
    if (parent != '.') cout << parent;
    
}

int main () {
    char temp[N][3] = {
        {'A', 'B', 'C'},
        {'B', 'D', '.'},
        {'C', 'E', 'F'},
        {'E', '.', '.'},
        {'F', '.', 'G'},
        {'D', '.', '.'},
        {'G', '.', '.'}
    };

    for (int i=0; i < N; i++) {
        arr[i][0] = temp[i][0];
        arr[i][1] = temp[i][1];
        arr[i][2] = temp[i][2];
    }
    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
}
