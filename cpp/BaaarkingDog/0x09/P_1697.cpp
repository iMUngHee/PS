/*
문제 : 1697번 숨바꼭질
등급 : 실버 1
링크 : https://www.acmicpc.net/problem/1697
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int dist[1000002];

queue<int> Q;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    fill(dist, dist + 100002, -1);
    cin >> n >> k;
    Q.push(n);
    dist[n] = 0;
    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        for(int nxt: {cur - 1, cur + 1, 2 * cur}){
            if(nxt < 0 or nxt > 100000) continue;
            if(dist[nxt] >= 0) continue;
            dist[nxt] = dist[cur] + 1;
            Q.push(nxt);
        }
    }
    cout << dist[k] << '\n';
    return 0;
}

/*
    수빈: 걷거나 순간이동 / 걸을 때 X+1 or X-1 / 순간이동 2*X
    동생: 점 K에 있음
    input:
        n => 수빈이 위치
        k => 동생 위치
    output:
        x => 최단 경우의 수
*/
