/*
? 문제 : 2636번 치즈
! 등급 : 골드 4
* 링크 : https://www.acmicpc.net/problem/2636
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

queue<pair<int, int>> Q;

int board[102][102];
int visited[102][102];

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int height, width;
int ans1, ans2;

void print() {
    cout << '\n';

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << visited[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> height >> width;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cin >> board[i][j];
        }
    }

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (!board[i][j] && !visited[i][j]) {
                int flag = 0;
                visited[i][j] = 1;
                Q.push({i, j});
                while (!Q.empty()) {
                    auto cur = Q.front();
                    Q.pop();

                    for (int dir = 0; dir < 4; dir++) {
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];

                        if (nx < 0 || nx >= height || ny < 0 || ny >= width) {
                            flag = 1;
                            continue;
                        }
                        if (board[nx][ny] || visited[nx][ny] < 0) continue;
                        visited[nx][ny] = flag ? -1 : -2;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }

    print();
    return 0;
}