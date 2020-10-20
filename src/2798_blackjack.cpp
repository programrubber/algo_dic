#include "iostream"
#define CARDSIZE 101

using namespace std;

// 딜러는 N장의 카드를 보이도록 놓는다. 그런 후 딜러는 숫자 M을 외친다.
// 플레이어는 3장의 카드를 골라야 한다.
// 플레이어는 M을 넘지 않으면서 M과 근접하도록 해야한다.

int N, M; // N: 카드의 갯수, M을 외침

// 조합
int K = 3; // 고를수 있는 카드 수
int cards[CARDSIZE];
int choise[4];
int combCnt=0;

int combList[CARDSIZE][4];
int pointList[CARDSIZE];

void comb(int num, int idx) {
    if (K<idx) {
        for (int i=1; i<=K; i++) {
            combList[combCnt][i] = choise[i];
        }
        combCnt++;
        return;
    }
    if (N<num) return;
    choise[idx] = cards[num];
    comb(num+1, idx+1);
    comb(num+1, idx);
}

void pointCalc() {
    for (int i=0; i<combCnt; i++) {
        int tot = 0;
        for (int j=1; j<=K; j++) {
            tot += combList[i][j];
        }
        pointList[i] = tot;
    }
}

void pointSelect() {
    int val = 0;
    for (int i=0; i<combCnt; i++) {
        int tot = pointList[i];
        if (M < tot) continue;
        if (val < tot) {
            val = tot;
        }
    }
    printf()
    cout << val;
}

int main () {
    cin >> N;
    cin >> M;
    if (3>N || N>100) return 0;
    if (10>M || M>300000) return 0;
    for (int i=1; i<=N; i++) {
        cin >> cards[i];
    }
    comb(1, 1); // 조합을 구한다.
    pointCalc(); // 조합의 포인트를 계산한다.
    pointSelect(); // 선택된 부분을 출력한다.
}
