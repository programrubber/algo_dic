// 2056. 연월일 달력: https://swexpertacademy.com/main/code/problem/problemDetail.do?contestProbId=AV5QLkdKAz4DFAUq&categoryId=AV5QLkdKAz4DFAUq&categoryType=CODE
#include<iostream>
#include<string>

using namespace std;

bool isCheckDate (int month, int date) {
    if (date == 0) return false;
    if (month < 1 || month > 12) return false;
    if (month == 2) // 28
    {
        if (date > 0 && date < 29) return true;
        return false;
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) // 30
    {
        if (date > 0 && date < 31) return true;
        return false;
    } else { // 31
        if (date > 0 && date < 32) return true;
        return false;
    }
    return false;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        string temp;
        cin >> temp;
        int year; string yearStr;
        int month; string monthStr;
        int date; string dateStr;
        for (int i=0; i<4; i++) {
            yearStr += temp[i];
        }
        for (int i=4; i<6; i++) {
            monthStr += temp[i];
        }
        for (int i=6; i<8; i++) {
            dateStr += temp[i];
        }
        
        year = stoi(yearStr);
        month = stoi(monthStr);
        date = stoi(dateStr);
        
        if (isCheckDate(month, date)) {
            cout << "#" << test_case << " " << yearStr << "/" << monthStr << "/" << dateStr << endl;    
        } else {
            cout << "#" << test_case << " -1" << endl;   
        }
	}
	return 0;
}
