/*
문제 : 2490번 윷놀이
등급 : 브론즈 3
링크 : https://www.acmicpc.net/problem/2490
*/
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = -1;
    int n;
    for (int j = 0; j < 3; j++) {
        for (int i = 0; i < 4; i++) {
            cin >> n;
            if (n == 0)
                cnt++;
        }
        if (cnt == -1)
            cout << 'E' << '\n';
        else
            cout << (char)('A' + cnt) << '\n';
        cnt = -1;
    }
    return 0;
}