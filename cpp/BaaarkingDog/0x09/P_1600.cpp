/*
문제 : 1600번 말이 되고픈 원숭이
등급 : 골드 4
링크 : https://www.acmicpc.net/problem/1600
*/
#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[202][202];
int dist[202][202][32];

queue<tuple<int,int,int>> Q;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int hx[8] = {2, 2, 1, -1, -2, -2, -1, 1};
int hy[8] = {-1, 1, 2, 2, 1, -1, -2, -2};

int w, h, k;

bool OOB(int a, int b){
    return a < 0 or b < 0 or a >= h or b >= w;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k;
    cin >> w >> h;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> board[i][j];
        }
    }
    dist[0][0][0] = 1;
    Q.push({0,0,0});
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        int x, y, horse;
        tie(x, y, horse) = cur;
        if(horse < k){
            for(int hDir = 0; hDir < 8; hDir++){
                int nx = x + hx[hDir];
                int ny = y + hy[hDir];
                if(OOB(nx,ny)) continue;
                if(board[nx][ny]) continue;
                if(dist[nx][ny][horse + 1]) continue;
                dist[nx][ny][horse + 1] = dist[x][y][horse] + 1;
                Q.push({nx,ny,horse + 1});
            }
        }
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(OOB(nx,ny)) continue;
            if(board[nx][ny]) continue;
            if(dist[nx][ny][horse]) continue;
            dist[nx][ny][horse] = dist[x][y][horse] + 1;
            Q.push({nx,ny,horse});
        }
    }
    int ans = 100000000;
    for (int i = 0; i < k + 1; i++)
        if(dist[h - 1][w - 1][i]) ans = min(ans, dist[h - 1][w - 1][i]);
    if (ans != 100000000) cout << ans - 1 << '\n';
    else cout << -1 << '\n';
    return 0;
}

/*
    말숭이
    k번은 날일자로 그 외는 한 번쓱 이동
    1은 장애물
    input:
        k => 날일자 가능 횟수 (1 <= k <= 30)
        w, h => 가로 세로 1 <= n, m <= 200
        배열 => 0은 길, 1은 장애물
    output:
        ans => 동작 최솟값, 불가 시 -1
*/
