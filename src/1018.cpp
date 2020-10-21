#include <iostream>
#include <string>

using namespace std;

char ground[50][50];
int N, M;

string whitePattern[8] = {
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
};
string blackPattern[8] = {
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
};

int whiteCheck (int x, int y) {
    int cnt = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (whitePattern[i][j] != ground[i+x][j+y]) cnt++;
        }
    }
    return cnt;
}

int blackCheck (int x, int y) {
    int cnt = 0;
    for (int i=0; i<8; i++) {
        for (int j=0; j<8; j++) {
            if (blackPattern[i][j] != ground[i+x][j+y]) cnt++;
        }
    }
    return cnt;
}

int main() {
    cin >> N; cin >> M;
    for (int i=0; i<N; i++) {
        string str;
        cin >> str;
        for (int j=0; j<M; j++) {
            ground[i][j] = str[j];
        }
    }
    int minVal = 12345;
    if (N<8 || N>50 || M<8 || M>50) return 0;
    for (int i=0; i < (N-7); i++) {
        for (int j=0; j < (M-7); j++) {
            int whiteVal = whiteCheck(i, j);
            int blackVal = blackCheck(i, j);
            if (whiteVal < minVal) minVal = whiteVal;
            if (blackVal < minVal) minVal = blackVal;
        }
    }
    cout << minVal;
    return 0;
}
