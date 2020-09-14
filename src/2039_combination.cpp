#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 1000

using namespace std;

int smuff[10]; // 9명의 난쟁이의 키 정보

int arr[10]; // 9명의 난쟁이 순서
int choise[8]; // 7명

int N = 9;  // 난쟁이 수
int K = 7;  // 진짜 난쟁이 수
int combList[SIZE][10];
int combSumList[SIZE];
int combCnt = 0;

void comb(int num, int idx) {
    if (idx > K) {
        combCnt++;
        for (int i=1; i<=K; i++) {
            combList[combCnt][i] = choise[i];
            // cout << "[" << combCnt << ","<< i << "]" <<choise[i] << " ";
        }
        cout << "\n";
        return;
    }
    if (num > N) return;
    choise[idx] = arr[num];
    comb(num+1, idx+1);
    comb(num+1, idx);
}

int sumComb(int idx) {
    int tot = 0;
    for (int i=1; i<=K; i++) {
        int index = combList[idx][i];
        int tall = smuff[index];
        // cout << "index: " << index << ", tall: " << tall << "\n";
        tot += tall;
    }
    
    return tot;
}

int main () {
    /*
    Test Inject Data
    int temp[10] = {0, 20, 7, 23, 19, 10, 15, 25, 8, 13};
    for (int i=1; i<=N; i++) {
        smuff[i] = temp[i];
    }
    */
    for (int i=1; i<10; i++) {
        cin >> smuff[i];
    }
    
    for (int i=1; i<=N; i++) {
        arr[i] = i;
    }
    comb(1,1);
    int findCombIndex = -1;
    for (int i=1; i<combCnt; i++) {
        int rst = sumComb(i);
        combSumList[i] = rst;
        // cout << rst << "\n";
        if (rst == 100) findCombIndex = i;
    }
    // cout << findCombIndex;
    vector <int> vec;
    for (int i=1; i<=K; i++) {
        int idx = combList[findCombIndex][i];
        int tall = smuff[idx];
        vec.push_back(tall);
    }
    sort(vec.begin(), vec.end());
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << "\n";
    }
}
