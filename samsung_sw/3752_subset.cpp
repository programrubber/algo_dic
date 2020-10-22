// 3752. 가능한 시험 점수: https://swexpertacademy.com/main/solvingProblem/solvingProblem.do
#include<iostream>
#include<vector>
#include<set>
#define SIZE 100

using namespace std;

int inputArr[SIZE][100];
int inputN[SIZE];

int N;
vector <int> cards;
int bits[100];
int caseCnt = 0;

set <int> keys;

void init() {
    N = 0;
    cards.clear();
    keys.clear();
    for(int i=0; i<100; i++) {
        bits[i] = 0;
    }
    caseCnt = 0;
}

// subset
void subset(int start, int end) {
    if (start == end){
        int tot = 0;
        for (int i=0; i<end; i++) {
            if (bits[i]) tot += cards[i];
        }
        keys.insert(tot);
        return;
    }
    bits[start] = 1; subset(start+1, end);
    bits[start] = 0; subset(start+1, end);
}


int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

    for (int i=1; i<=T; i++) {
        cin >> inputN[i];
        for (int j=0; j<inputN[i]; j++) {
            cin >> inputArr[i][j];
        }
    }
	for(test_case = 1; test_case <= T; ++test_case)
	{
	    init();
	    N = inputN[test_case];
        for (int i=0; i<N; i++) {
            cards.push_back(inputArr[test_case][i]);
        }
        subset(0, N);
        cout << "#" << test_case << " " << keys.size() << endl;
	}
	return 0;
}
