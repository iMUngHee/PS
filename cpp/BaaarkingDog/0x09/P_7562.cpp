/*
문제 : 7562번 나이트의 이동
등급 : 실버 2
링크 : https://www.acmicpc.net/problem/7562
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[302][302];
int dist[302][302];


int dx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        queue<pair<int, int>> Q;
        int I;
        int x, y, p, q;
        cin >> I;
        cin >> x >> y;
        cin >> p >> q;
        for(int i = 0; i < I; i++){
            fill(dist[i], dist[i] + I, -1);
        }
        Q.push({x, y});
        dist[x][y] = 0;
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            if(cur.X == p and cur.Y == q) break;
            for(int dir = 0; dir < 8; dir++){
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if(nx < 0 or nx >= I or ny < 0 or ny >= I) continue;
                if(dist[nx][ny] >= 0) continue;
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                Q.push({nx, ny});
            }
        }
        cout << dist[p][q] << '\n';
    }
    return 0;
}

/*
    나이트 이동
    날일자로 가는 나이트... 몇 번 가면 목적지로 가는가
    input:
        tc => test case
        I => I x I 그리드 4 <= I <= 300
        x, y => 현재 위치
        p, q => 목적지
    output:
        ans => 최소 이동 횟수
*/
