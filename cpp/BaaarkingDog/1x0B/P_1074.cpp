/*
문제 : 1074번 Z
등급 :  실버 1
링크 : https://www.acmicpc.net/problem/1074
*/
#include <iostream>

using namespace std;

int n, r, c;

int solve(int n, int r, int c){
    if(n == 0) return 0;
    int half = 1<<(n-1);
    if(r < half && c < half) return solve(n-1, r, c);
    if(r < half && c >= half) return half * half + solve(n-1, r, c - half);
    if(r >= half && c < half) return 2 * half * half + solve(n-1, r - half, c);
    return 3 * half * half + solve(n-1, r - half, c - half);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> r >> c;
    cout << solve(n, r, c) << '\n';
    return 0;
}