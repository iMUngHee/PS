/*
문제 : 10093번 숫자
등급 : 브론즈 2
링크 : https://www.acmicpc.net/problem/10093
*/
#include <iostream>
#include <algorithm>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    long long a = 0, b = 0;
    cin >> a >> b;
    if (a > b) {
        long long tmp = a;
        a = b;
        b = tmp;
    }
    if (a == b || b - a == 1)
        cout << 0;
    else {
        cout << b - a - 1 << "\n";
        for (long long i = a + 1; i < b; i++)
            cout << i << " ";
    }
    cout << '\n';
    return 0;
}