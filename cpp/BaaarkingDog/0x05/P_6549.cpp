/*
문제 : 6549번 히스토그램에서 가장 큰 직사각형
등급 : 플레티넘 5
링크 : https://www.acmicpc.net/problem/6549
*/
#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

stack<pair<long long, long long>> hist;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        int n;
        long long ans = 0;
        cin >> n;
        if(n == 0) break;
        for(int i = 0; i < n; i++){
            int h;
            cin >> h;
            int idx = i;
            while(!hist.empty() && hist.top().first >= h){
                ans = max(ans, (i - hist.top().second) * hist.top().first);
                idx = hist.top().second;
                hist.pop();
            }
            hist.push({h, idx});
        }
        while(!hist.empty()){
            ans = max(ans, (n - hist.top().second) * hist.top().first);
            hist.pop();
        }
        cout << ans << '\n';
    }
    return 0;
}

/*
    히스토그램

    입력:
        N => 히스토그램의 가로 칸의 수 ( 1 <= N <= 100,000 )
        h => 각 사람의 키 ( 0 <= h <= 1,000,000,000 )
    출력:
        ans => 가장 큰 직사각형의 넓이 ( 0 <= ans < 2,000,000,000 )
*/
