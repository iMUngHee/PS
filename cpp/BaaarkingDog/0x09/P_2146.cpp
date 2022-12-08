/*
문제 : 2146번 다리 만들기
등급 : 골드 3
링크 : https://www.acmicpc.net/problem/2146
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

int board[102][102];
int vis[102][102];
int dist[102][102];

queue<pair<int,int>> I;
queue<pair<int,int>> W;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int idx = 1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> board[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] && !vis[i][j]){
                vis[i][j] = 1;
                I.push({i,j});
                while(!I.empty()){
                    auto cur = I.front(); I.pop();
                    board[cur.X][cur.Y] = idx;
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if(!board[nx][ny] || vis[nx][ny]) continue;
                        vis[nx][ny] = 1;
                        I.push({nx,ny});
                    }
                }
                idx++;
            }
            if(!board[i][j]){
                dist[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] != 0){
                W.push({i,j});
            }
        }
    }
    int ans = 999999;
    while(!W.empty()){
        auto cur = W.front(); W.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            if(board[nx][ny] == board[cur.X][cur.Y]) continue;
            if(board[nx][ny] != 0){
                if(ans > dist[nx][ny] + dist[cur.X][cur.Y]){
                    ans = dist[nx][ny] + dist[cur.X][cur.Y];
                }
            } else{
                board[nx][ny] = board[cur.X][cur.Y];
                dist[nx][ny] = dist[cur.X][cur.Y] + 1;
                W.push({nx,ny});
            }
            
        }
    }
    cout << ans << '\n';
    return 0;
}

/*
    다리 건설
    N x N 정사각형 맵
    1은 육지, 0은 바다
    두 개 이상의 섬이 있음
    가장 짧은 다리를 만들어서 섬들 중 두 개를 연결시켜야 함
    가장 짧은 다리는 격자가 차지하는 칸의 수가 가장 작은 다리임
    input:
        n => 정사각형 n x n |  1 <= n <= 100
        배열 => 1은 육지 0은 바다
    output:
        ans => 가장 짧은 다리 길이
*/
