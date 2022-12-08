/*
문제 : 10026번 적록색약
등급 : 골드 5
링크 : https://www.acmicpc.net/problem/10026
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

queue<pair<int, int>> Q;

string board[102];

int RG[102][102];  // 적록색약 관점

int R[102][102];
int G[102][102];

int B[102][102];

int n, nRGB, RGB;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((board[i][j] == 'R' or board[i][j] == 'G') and !RG[i][j]){
                nRGB++;
                RG[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()){
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                        if(board[nx][ny] == 'B'  or RG[nx][ny]) continue;
                        RG[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((board[i][j] == 'B') and !B[i][j]){
                nRGB++;
                RGB++;
                B[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()){
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                        if(board[nx][ny] != 'B'  or B[nx][ny]) continue;
                        B[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((board[i][j] == 'R') and !R[i][j]){
                RGB++;
                R[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()){
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                        if(board[nx][ny] != 'R'  or R[nx][ny]) continue;
                        R[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if((board[i][j] == 'G') and !G[i][j]){
                RGB++;
                G[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()){
                    auto cur = Q.front();
                    Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                        if(board[nx][ny] != 'G'  or G[nx][ny]) continue;
                        G[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
            }
        }
    }
    cout << RGB << ' ' << nRGB << '\n';
    return 0;
}

/*
    적록색약
    색약 - RG 는 동일 B따로
    안-색약 - RGB 따로따로
    Red => 1
    Green => 2
    Blue => 3
    input:
        n => n x n 그리도
        RGB => 배열
    output:
        nRGB => 적록색약 아닌 사람 관점
        RGB => 적록색약 관점
*/
