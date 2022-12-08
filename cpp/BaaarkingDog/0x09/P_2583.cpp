/*
문제 : 2583번 영역 구하기
등급 : 실버 1
링크 : https://www.acmicpc.net/problem/2583
*/
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

#define X first
#define Y second

using namespace std;

int board[102][102];
int vis[102][102];

queue<pair<int,int>> Q;
vector<int> V;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n, m, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    while(k--){
        int x, y, p, q;
        cin >> y >> x >> q >> p;
        for(int i = x; i < p; i++){
            for(int j = y; j < q; j++){
                board[i][j] = -1;
            }
        }
    }
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(board[i][j] == 0 && vis[i][j] == 0){
                num++;
                int area = 0;
                vis[i][j] = 1;
                Q.push({i, j});
                while(!Q.empty()){
                    area++;
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
                        if(board[nx][ny] == -1 or vis[nx][ny] != 0) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx, ny});
                    }
                }
                V.push_back(area);
            }
        }
    }
    cout << num << '\n';
    sort(V.begin(), V.end());
    for(int a: V) cout << a << ' ';
    cout << '\n';
    return 0;
}

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
/*
    
    input:
        n, m => 세로 | 가로 1 <= n, m <= 100
        k => 좌표 개수 1 <= k <= 100
        x, y => 직사각형 우하귀 점
        p, q => 직사각형 좌상귀 점
    output:
        ans => 배추밭에 필요한 지렁이 수
*/
