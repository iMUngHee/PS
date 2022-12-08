/*
문제 : 6593번 상범 빌ㅣ
등급 : 골드 5
링크 : https://www.acmicpc.net/problem/6593
*/
#include <iostream>
#include <queue>
#include <tuple>

#define Z 0
#define X 1
#define Y 2

using namespace std;

int dz[3] = {-1, 0, 1};
int dx[5] = {1, 0, -1, 0, 0};  //  바로 위 아래층 검사 포함 
int dy[5] = {0, 1, 0, -1, 0};  //  바로 위 아래층 검사 포함

int l, r, c;  // 높이 세로 가로

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while (1) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) return 0;
        string board[32][32];
        int dist[32][32][32] = {0};
        queue<tuple<int, int, int>> Q;
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                cin >> board[i][j];
            }
        }
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < r; j++) {
                for (int k = 0; k < c; k++) {
                    if (board[i][j][k] == '.' or board[i][j][k] == 'E') {
                        dist[i][j][k] = -1;
                    }
                    if (board[i][j][k] == 'S') {
                        Q.push({i, j, k});
                    }
                }
            }
        }
        bool esc = false;
        while (!Q.empty() && !esc) {
            auto cur = Q.front();
            Q.pop();
            for (int dirZ = 0; dirZ < 3; dirZ++) {
                int nz = get<Z>(cur) + dz[dirZ];
                if (nz < 0 or nz >= l) continue;
                for (int dir = 0; dir < 5; dir++) {
                    int nx = get<X>(cur) + dx[dir];
                    int ny = get<Y>(cur) + dy[dir];
                    if (dz[dirZ] != 0 && (dx[dir] != 0 or dy[dir] != 0))
                        continue;
                    if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
                    if (dist[nz][nx][ny] >= 0) continue;
                    if (board[nz][nx][ny] == 'E') {
                        cout << "Escaped in "
                            << dist[get<Z>(cur)][get<X>(cur)][get<Y>(cur)] + 1
                            << " minute(s).\n";
                        esc = true;
                        break;
                    }
                    // cout << nz << ' ' << nx << ' ' << ny << '\n';
                    dist[nz][nx][ny] =
                        dist[get<Z>(cur)][get<X>(cur)][get<Y>(cur)] + 1;
                    Q.push({nz, nx, ny});
                }
                if (esc) break;
            }
        }
        if (!esc) cout << "Trapped!" << '\n';
    }
    return 0;
}

/*
    방탈출
    대각선 이동 불가
    상하좌우앞뒤
    input:
        l, r, c => 높이 세로 가로 1 <= l, r, c <= 30
        배열 => 벽: #, 이동 가능: ., 시작 지점: S, 탈출구: E
            각 층 사이에는 빈 줄
            입력의 끝은 l, r, c 모두가 0일 때
    output:
        ans => 최소 시간 Escaped in {ans} minute(s).
            탈출 불가일 때는 Trapped!
*/
