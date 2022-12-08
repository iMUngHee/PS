/*
문제 : 2667번 단지 번호 붙이기
등급 : 실버 1
링크 : https://www.acmicpc.net/problem/2667
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

#define X first
#define Y second

using namespace std;

queue<pair<int,int>> Q;
vector<int> V;

string board[27];
int vis[27][27];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> board[i];
    }
    int num = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(board[i][j] == '1'){
                vis[i][j] = -1;
            }
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(vis[i][j] == -1){
                num++;
                int area = 0;
                vis[i][j] = 1;
                Q.push({i,j});
                while(!Q.empty()){
                    area++;
                    auto cur = Q.front(); Q.pop();
                    for(int dir = 0; dir < 4; dir++){
                        int nx = cur.X + dx[dir];
                        int ny = cur.Y + dy[dir];
                        if(nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
                        if(vis[nx][ny] != -1) continue;
                        vis[nx][ny] = 1;
                        Q.push({nx,ny});
                    }
                }
                V.push_back(area);
            }
        }
    }
    sort(V.begin(), V.end());
    cout << num << '\n';
    for(int a: V) cout << a << '\n';
    return 0;
}

/*
    정사각형
    1 집잇다
    0 없다
    연결되어 있는 곳이 단지
    단지수 출력
    각 단지에 속하는 집의 수 출력
    input:
        n => 정사각형 5 <= n <= 25
        배열
    output:
        ans => 단지수
        vector => 각 단지에 속한 집의 수 (오름차순)
*/
