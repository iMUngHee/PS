/*
문제 : 11967번 불켜기
등급 : 골드 3
링크 : https://www.acmicpc.net/problem/11967
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

queue<pair<int,int>> Q;
queue<pair<int,int>> light[102][102];
int vis[102][102];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    while(m--){
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        light[x][y].push({a, b});
    }
    vis[1][1] = 1;
    Q.push({1, 1});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        while(!light[cur.X][cur.Y].empty()){
            auto lCur = light[cur.X][cur.Y].front();
            light[cur.X][cur.Y].pop();
            if(vis[lCur.X][lCur.Y] != 1) vis[lCur.X][lCur.Y] = -1;
            for(int dir = 0; dir < 4; dir++){
                int nx = lCur.X + dx[dir];
                int ny = lCur.Y + dy[dir];
                if(nx < 0 or nx > n or ny < 0 or ny > n) continue;
                if(vis[nx][ny] != 1) continue;
                vis[lCur.X][lCur.Y] = 1;
                Q.push({lCur.X, lCur.Y});
            }
        }
        for(int dir = 0; dir < 4; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 or nx > n or ny < 0 or ny > n) continue;
                if(vis[nx][ny] != -1) continue;
                vis[nx][ny] = 1;
                Q.push({nx, ny});
            }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(vis[i][j]) ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}

/*
    NxN 방 각 방은 (1,1)부터 (N,N)까지 번호가 매겨져있음
    유일하게 불이 켜져 있는 (1,1)에서 출발
    어떤 방에는 다른 방의 불을 끄고 켤 수 있는 스위치가 있음
    불이 켜져있는 방으로만 갈 수 있음
    각 방에서는 상하좌우로 인접한 방만 갈 수 있음
    불을 켤 수 있는 최대 개수
    input:
        n, m => n: 방 크기, m: 스위치가 있는 방
            2 <= n <= 100, 1 <= m <= 20,000
        x, y, a, b => (x,y)방에서 (a,b)방 불 컨트롤 가능
    output:
        ans => 불을 켤 수 있는 방의 최대 개수
    0 0 0
    0 0 0
    0 0 0
*/
