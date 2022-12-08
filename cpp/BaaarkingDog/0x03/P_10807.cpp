/*
문제 : 10807번 개수 세기
등급 : 브론즈 2
링크 : https://www.acmicpc.net/problem/10807
*/
#include <iostream>
using namespace std;

int ans[201];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        int k = 0;
        cin >> k;
        ans[k + 100]++;
    }
    int v = 0;
    cin >> v;
    cout << ans[v + 100] << '\n';
    return 0;
}
