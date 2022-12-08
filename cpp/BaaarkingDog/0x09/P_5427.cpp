/*
문제 : 5427번 불
등급 : 골드 4
링크 : https://www.acmicpc.net/problem/5427
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        string board[1002];
        int distF[1002][1002] = {};
        int distS[1002][1002] = {};
        queue<pair<int, int>> F;
        queue<pair<int, int>> S;
        int w, h;
        cin >> w >> h;
        for(int i = 0; i < h;i++){
            cin >> board[i];
        }
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (board[i][j] == '.') {
                    distF[i][j] = -1;
                    distS[i][j] = -1;
                }
                if (board[i][j] == '*') F.push({i, j});
                if (board[i][j] == '@') {
                    distF[i][j] = -1;
                    S.push({i, j});
                }
            }
        }
        while (!F.empty()) {
            auto cur = F.front();
            F.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 or nx >= h or ny < 0 or ny >= w) continue;
                if (distF[nx][ny] >= 0) continue;
                distF[nx][ny] = distF[cur.X][cur.Y] + 1;
                F.push({nx, ny});
            }
        }
        bool esc = false;
        while (!S.empty()) {
            auto cur = S.front();
            S.pop();
            for (int dir = 0; dir < 4; dir++) {
                int nx = cur.X + dx[dir];
                int ny = cur.Y + dy[dir];
                if (nx < 0 or nx >= h or ny < 0 or ny >= w) {
                    esc = true;
                    cout << distS[cur.X][cur.Y] + 1 << '\n';
                    break;
                }
                if (distS[nx][ny] >= 0) continue;
                if (distF[nx][ny] >= 0 and (distS[cur.X][cur.Y] + 1 >= distF[nx][ny])) 
                    continue;
                distS[nx][ny] = distS[cur.X][cur.Y] + 1;
                S.push({nx, ny});
            }
            if (esc) break;
        }
        if (!esc) cout << "IMPOSSIBLE" << '\n';
    }

    return 0;
}

/*
    !!! @@@ string 입력 주의 @@@ !!!
    '.': 빈 공간
    '#': 벽
    '@': 상근이의 시작 위치
    '*': 불
    input:
        tc => test case
        w, h => 너비, 높이 1 <= w, h <= 1000
        배열
    output:
        ans => 최소 탈출 시간
*/
