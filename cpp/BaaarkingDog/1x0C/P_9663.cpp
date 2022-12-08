/*
문제 : 9663번 N-Queen
등급 :  골드 5
링크 : https://www.acmicpc.net/problem/9663
*/
#include <iostream>

using namespace std;

bool isUsed1[40];
bool isUsed2[40];
bool isUsed3[40];

int n, ans = 0;


void solve(int k){
    if( k == n) {
        ans++;
        return;
    }
    for(int i = 0; i < n; i++){
        if(isUsed1[i] || isUsed2[i + k] || isUsed3[k - i + n - 1])
            continue;
        isUsed1[i] = 1;
        isUsed2[i + k] = 1;
        isUsed3[k - i + n - 1] = 1;
        solve(k + 1);
        isUsed1[i] = 0;
        isUsed2[i + k] = 0;
        isUsed3[k - i + n - 1] = 0;
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    solve(0);
    cout << ans << '\n';
    return 0;
}