#include <stdio.h>
#include <iostream>

using namespace std;

// 재귀 함수를 이용한 유클리드 호제법
int gcd (int num1, int num2) {
    cout << "process: " << num1 << ", " << num2 << endl;
    if (num2 == 0) {
        return num1;
    } else {
        return gcd(num2, num1 % num2);
    }
}

int main()
{
    int a ,b;
    int result;
    cin >> a;
    cin >> b;
    
    result = gcd(a, b);
    cout << result << endl;
    return 0;
}
