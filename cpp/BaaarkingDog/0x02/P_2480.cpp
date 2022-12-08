/*
문제 : 2480번 주사위 세개
등급 : 브론즈 4
링크 : https://www.acmicpc.net/problem/2480
*/
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if(a == b && b == c) ans = 10000 + a * 1000;
    else if(a != b && b != c && a != c) {
        int temp = a > b ? a : b;
        temp = temp > c ? temp : c;
        ans = temp * 100;
    }else {
        if(a==b) ans += 1000 + a * 100;
        else ans += 1000 + 100 * (a == c ? a : c);
    }
    cout << ans << '\n';
    return 0;
}