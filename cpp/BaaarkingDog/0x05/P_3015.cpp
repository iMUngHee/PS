/*
문제 : 3015번 오아시스 재결합
등급 : 골드 1
링크 : https://www.acmicpc.net/problem/3015
*/
#include <iostream>
#include <stack>

using namespace std;

stack<pair<int, int>> order;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;
        int cnt = 1;
        while (!order.empty() && order.top().first <= h) {
            ans += order.top().second;
            /* 2. j == k */
            if (order.top().first == h) {
                cnt += order.top().second;
            }
            /* 3. j < k */
            else {
                cnt = 1;
            }
            order.pop();
        }
        /* 1. j > k  */
        if (!order.empty()) ans++;
        order.push({h, cnt});
    }
    cout << ans << '\n';
    return 0;
}

/*
    N명이 한 줄로 서있음
    A와 B가 서로 볼 수 있으려면, 두 사람 사이에 A 또는 B보다 키 큰 사람 없어야 됨

    입력:
        N => 기다리고 있는 사람의 수 ( 1 <= N <= 500,000)
        h => 각 사람의 키 ( 1 <= h <= 2^31 )
    출력:
        ans => 서로 볼 수 있는 쌍의 수
*/
