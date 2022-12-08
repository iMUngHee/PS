/*
문제 : 2576번 홀수
등급 : 브론즈 3
링크 : https://www.acmicpc.net/problem/2576
*/
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int min = 101, ans = 0;
    for (int i = 0; i < 7; i++) {
        int tmp = 0;
        cin >> tmp;
        if (tmp % 2 != 0) {
            ans += tmp;
            min = min < tmp ? min : tmp;
        }
    }
    if (ans == 0) {
        cout << -1 << '\n';
    } else {
        cout << ans << '\n';
        cout << min << '\n';
    }
    return 0;
}