/*
문제 : 1463번 1로 만들기
등급 : 실버 3
링크 : https://www.acmicpc.net/problem/1463
*/
#include <iostream>

using namespace std;

int n, ans = 1000002;
int dp[1000002];

void solve(int n) {
    if (n == 1) {
        ans = ans > dp[n] ? dp[n] : ans;
        return;
    }
    if (n % 3 == 0) {
        if (!dp[n / 3] or dp[n] + 1 < dp[n / 3]) {
            dp[n / 3] = dp[n] + 1;
            solve(n / 3);
        }
    }
    if (n % 2 == 0) {
        if (!dp[n / 2] or dp[n] + 1 < dp[n / 2]) {
            dp[n / 2] = dp[n] + 1;
            solve(n / 2);
        }
    }
    dp[n - 1] = dp[n] + 1;
    solve(n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    solve(n);
    cout << ans << '\n';
    return 0;
}