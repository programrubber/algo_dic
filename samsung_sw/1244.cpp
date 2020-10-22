// 1244. [S/W 문제해결 응용] 2일차 - 최대 상금: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV15Khn6AN0CFAYD&categoryId=AV15Khn6AN0CFAYD&categoryType=CODE
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define SIZE 100

using namespace std;
// input
string inputStr[SIZE];
int inputCnt[SIZE];

// reverse
int maxCash = 0;
char cards[10];
int N = 0;

void init () {
    maxCash = 0;
    N = 0;
    // for (int i=0; i<10; i++) {
    //     cards[i] = '';
    // }
}
int tcnt=0;
void reverseCheck(int num, int cnt) { // 2 1
    if (cnt == 0) {
        string temp = "";
        for (int i=0; i<N; i++) {
            temp += cards[i];
        }
        int num = stoi(temp);

        if (maxCash < num) {
            maxCash = num;
        }
        return;
    }
    
    if (num == 0 && cnt == 1) {
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) {
                if (cards[i] < cards[j]) {
                    if (j!=i) swap(cards[j], cards[i]);
                    reverseCheck(j+1, cnt-1);
                    if (j!=i) swap(cards[j], cards[i]);
                }
            }
        }
    } else if (num == N) {
        reverseCheck(num+1, cnt-1);
        return;
    } else {
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (cards[i] < cards[j]) {
                    if (j!=i) swap(cards[j], cards[i]);
                    reverseCheck(j+1, cnt-1);
                    if (j!=i) swap(cards[j], cards[i]);
                }
            }
        }
    }
    if (maxCash == 0) {
        string temp = "";
        for (int i=0; i<N; i++) {
            temp += cards[i];
        }
        int num = stoi(temp);
        maxCash = num;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for (int i=1; i<=T; i++) {
	    cin >> inputStr[i];
	    cin >> inputCnt[i];
	}
	for(test_case = 1; test_case <= T; ++test_case)
	{
	    init();
	    // inject
        N = inputStr[test_case].length();
        for (int i=0; i<N; i++) {
            cards[i] = inputStr[test_case][i];
        }
        int cnt = inputCnt[test_case];
        
        // recursive
        reverseCheck(0, cnt);
        cout << "#" << test_case << " " << maxCash << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
