/*
문제 : 2512번 예산
등급 : 실버 3
링크 : https://www.acmicpc.net/problem/2512
*/
#include <iostream>
using namespace std;

int n, m;
int k[100002];

int ans;

bool check(int mid) {
    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += k[i] <= mid ? k[i] : mid;
    }

    if (sum > m)
        return true;
    else {
        ans = mid;
        return false;
    }
}

void binary_search(int min, int max) {
    const bool isTop = check((min + max) / 2);
    if (min == max) return;

    if (isTop)
        binary_search(min, (min + max) / 2);
    else
        binary_search((min + max) / 2 + 1, max);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int max = -1;

    cin >> n;

    for (size_t i = 0; i < n; i++) {
        cin >> k[i];
        if (k[i] > max) max = k[i];
    }

    cin >> m;

    binary_search(0, max);

    cout << ans << '\n';

    return 0;
}