/*
문제 : 1182번 부분수열의 합
등급 :  실버 2
링크 : https://www.acmicpc.net/problem/1182
*/
#include <iostream>

using namespace std;

int arr[22];
int isUsed[22];
int n, s;
int ans;

void solve(int cur, int sum){
    if(cur == n){
        if(sum == s) ans++;
        return;
        }    
    solve(cur + 1, sum);
    solve(cur + 1, sum + arr[cur]);
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 0; i < n; i++) cin >> arr[i];
    solve(0, 0);
    if(s == 0) ans--;
    cout << ans << '\n';
    return 0;
}