// 2819. 격자판의 숫자 이어 붙이기: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV7I5fgqEogDFAXB&categoryId=AV7I5fgqEogDFAXB&categoryType=CODE
// 테스트는 성공했으나 제출했을때에 알 수 없는 Runtime Error
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string testArr[11][4];

string map[4];

vector <string> vec;

bool isFind(string str) {
    for (int i=0; i<vec.size(); i++) {
        if (vec[i] == str) return true;
    }
    return false;
}

void init() {
    for (int i=0; i<4; i++) {
        for (int j=0; j<4; j++) {
            map[i][j] = 0;
        }
    }
    vec.clear();
}

int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
void dfs(int x, int y, int cnt, string path) {
    path += map[x][y];
    if (cnt == 0) {
        if (!isFind(path)) vec.push_back(path);
        // cout << path << endl;
        return;
    }
    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx < 0 || ny < 0) continue;
        if (nx >= 4 || ny >= 4) continue;
        dfs(nx, ny, cnt-1, path);
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;
	
	for (int i=1; i<=T; i++) {
	    for (int j=0; j<4; j++) {
	        string str = "";
	        for (int k=0; k<4; k++) {
	            char tmp;
	            cin >> tmp;
	            str += tmp;
	        }
	        testArr[i][j] = str;
	    }
	}
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        init();
        // inject
        for (int i=0; i<4; i++) {
            map[i] = testArr[test_case][i];
        }
        for (int i=0; i<4; i++) {
            for (int j=0; j<4; j++) {
                dfs(i, j, 6, "");
            }
        }

        cout << "#" << test_case << " " << vec.size() << "\n";
	}
	return 0;
}
