// 덩치 https://www.acmicpc.net/problem/7568
#include <iostream>
#define SIZE 51
#define CS 1000

using namespace std;

int spec[SIZE][3];
//comb
int N, K=2;
int choise[SIZE];
int arr[SIZE];
int combCnt = 0;
int combList[CS][2];
void comb(int num, int idx) {
    if (K < idx) {
        for (int i=1; i<=K; i++) {
            combList[combCnt][i] = choise[i];
        }
        combCnt++;
        return;
    }
    if (N < num) return;
    choise[idx] = arr[num];
    comb(num+1, idx+1);
    comb(num+1, idx);
}

void battle() {
    for (int i=1; i<=N; i++) {
        int aWeight = spec[i][0];
        int aTall = spec[i][1];
        int cnt = 1;
        for (int j=0; j<combCnt; i++) {
            int bWeight, bTall;
            int idx = -1;
            if (combList[j][0] == i) idx = combList[j][1];
            if (combList[j][1] == i) idx = combList[j][0];
            if (idx == -1) continue;
            bWeight = spec[idx][0];
            bTall = spec[idx][1];
            if (aWeight < bWeight && aTall < bTall) {
                cnt++;
            }
        }
        spec[i][2] = cnt;
    }
}

void result () {
    for (int i=1; i<=N; i++) {
        cout << spec[i][2] << " ";
    }
}

int main () {
    cin >> N;
    for (int i=1; i<=N; i++) {
        arr[i] = i;
        int weight, tall;
        cin >> weight;
        cin >> tall;
        spec[i][0] = weight;
        spec[i][1] = tall;
    }
    comb(1, 1);
    battle();
    result();
}
