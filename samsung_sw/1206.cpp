#include<iostream>
#define WIDTH 1000
#define HEIGHT 255
#define TSIZE 1000

using namespace std;

int map[WIDTH][HEIGHT];
int N;

int arr[TSIZE][WIDTH];
int testN[TSIZE];

void mapClear() {
    for (int i=0; i<WIDTH; i++) {
        for (int j=0; j<WIDTH; j++) {
            map[i][j] = 0;
        }
    }
}

bool viewPoint (int x, int y) {
    if (map[x-1][y] || map[x-2][y] || map[x+1][y] || map[x+2][y]) return false;
    return true;
}

int viewCheck() {
   int cnt = 0;
   for (int i=0; i<N; i++) {
       for (int j=0; j<255; j++) {
           if (map[i][j] == 0) break;
           if (viewPoint(i, j)) cnt++;
       }
   }
   return cnt;
}

int main(int argc, char** argv)
{
	int test_case;
  // cin >> T;
	int T=10;
    
    for (int i=0; i<T; i++) {
        cin >> testN[i];
        for (int j=0; j<testN[i]; j++) {
            cin >> arr[i][j];
        }
    }
	for(test_case = 1; test_case <= T; ++test_case)
	{
        N = testN[test_case-1];
		    // 맵에 삽입
        for (int i=0; i<N; i++) {
            int height = arr[test_case-1][i];
            for (int j=0; j<height; j++) {
                map[i][j] = 1;
            }
        }
        int cnt = viewCheck();
        cout << "#" << test_case << " "<< cnt << endl;
        mapClear();
	}
	return 0;
}
