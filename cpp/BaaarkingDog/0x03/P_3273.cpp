/*
문제 : 3273번 두 수의 합
등급 : 실버 3
링크 : https://www.acmicpc.net/problem/3273
*/
#include <iostream>
using namespace std;

int num[2000001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        num[a]++;
    }
    int x;
    cin >> x;
    int ans = 0;
    for(int i = 1; i < (x + 1) / 2; i++){
        if(num[x - i] && num[i]) ans++;
    }
    cout << ans << '\n';
    return 0;
}

/*
    1 <= n <= 100,000
    1 <= a <= 1,000,000
    1 <= x <= 2,000,000

    ai + aj = x
*/