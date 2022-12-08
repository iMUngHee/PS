/*
문제 : 1629번 곱셈
등급 :  실버 1
링크 : https://www.acmicpc.net/problem/1629
*/
#include <iostream>

#define ll long long

using namespace std;

ll a, b, c;

int solve(ll a, ll b, ll c){
    if(b == 1) return a % c;
    ll val = solve(a, b/2, c);
    val = val * val % c;
    if(b%2 == 0) return val;
    return val * a % c;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b >> c;
    ll ans = solve(a, b, c);
    cout << ans << '\n';
    return 0;
}