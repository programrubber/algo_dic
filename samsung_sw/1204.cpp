// 1204. [S/W 문제해결 기본] 1일차 - 최빈수 구하기: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV13zo1KAAACFAYh&categoryId=AV13zo1KAAACFAYh&categoryType=CODE
#include<iostream>
#include<vector>

using namespace std;

int input[11][1000];
int N;

int cntList[101];

void initCntList () {
    for (int i=0; i<=100; i++) {
        cntList[i] = 0;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for (int i=1; i<=T; i++) {
	    int num;
	    cin >> num;
	    for (int j=0; j<1000; j++) {
	        cin >> input[i][j];
	    }
	}
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
		// TODO
		initCntList();
		for (int i=0; i<1000; i++) {
		    int num = input[test_case][i];
		    cntList[num]++;
		}
		int maxIdx = -1;
		for (int i=0; i<=100; i++) {
		    if (maxIdx == -1) maxIdx = 0;
		    if (cntList[maxIdx] < cntList[i]) {
		        maxIdx = i;
		    }
		    if (cntList[maxIdx] == cntList[i] && maxIdx < i) {
		        maxIdx = i;
		    }
		}
        cout << "#" << test_case << " " << maxIdx << "\n";
	}
	return 0;
}
