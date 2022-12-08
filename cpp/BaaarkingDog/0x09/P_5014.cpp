/*
문제 : 5014번 스타트링크
등급 : 골드 5
링크 : https://www.acmicpc.net/problem/5014
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int dist[1000002];

queue<int> Q;

int f, s, g;
int u, d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> f >> s >> g >> u >> d;
    fill(dist, dist + f + 1, -1);
    dist[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
        int cur = Q.front();
        Q.pop();
        if (cur == g) {
            cout << dist[cur]<< '\n';
            return 0;
        }
        for (int i : {u, d * (-1)}) {
            int nx = cur + i;
            if (nx <= 0 or nx > f) continue;
            if (dist[nx] >= 0) continue;
            dist[nx] = dist[cur] + 1;
            Q.push(nx);
        }
    }
    cout << "use the stairs" << '\n';
    return 0;
}

/*
    F층으로 이루어진 고층 건물
    G층에 있는 회사
    S층에 있는 강호
    엘베를 타고 올라갈려함
    U층 위로 가는 U버튼
    D층 아래로 가는 D버튼
    몇 번 눌러서 가야 할까요
    input:
        f, s, g => 1 <= s, g, f <= 1,000,000 F층이 최고층
        u, d => 0 <= u, d <= 1,000,000
    output:
        ans => 눌러야 하는 버튼의 수 최솟값 | 이동할 수 없을 때는 'use the
   stairs'
*/
