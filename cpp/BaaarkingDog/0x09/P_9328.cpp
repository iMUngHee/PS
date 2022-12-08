/*
문제 : 9328번 열쇠
등급 : 골드 1
링크 : https://www.acmicpc.net/problem/9328
*/
#include <iostream>
#include <tuple>
#include <vector>
#include <queue>

#define X 0
#define Y 1
#define T 2
using namespace std;

queue<tuple<int,int,int>> Q;

int tc;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> tc;
	while(tc--){
        vector<pair<int,int>> start;
		string board[102];
		int vis[102][102] = {0};
		int w, h;
		int ans = 0;
		cin >> h >> w;
		string key;
		for(int i = 0; i < h; i++){
			cin >> board[i];
		}
		cin >> key;
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				if(board[i][j] == '*'){
                    vis[i][j] = -1;
				}
				if((i == 0 or i == h - 1 or j == 0 or j == w - 1) && vis[i][j] == 0){
					vis[i][j] = 1;
					Q.push({i, j, 0});
                    start.push_back({i, j});
					if(board[i][j] == '$'){
						board[i][j] = '.';
						ans++;
					}
				}
			}
		}
        while(!Q.empty()){
            auto cur = Q.front(); Q.pop();
            int x, y, turn;
            tie(x, y, turn) = cur;
            if('A' <= board[x][y] && board[x][y] <= 'Z'){
                for(char c: key){
                    if(board[x][y] - 'A' == c - 'a'){
                        board[x][y] = '.';
                    }
                }
            }
            if(board[x][y] != '.') continue;
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir];
                int ny = y + dy[dir];
                if(nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if('A' <= board[nx][ny] && board[nx][ny] <= 'Z'){
                    for(char c: key){
						if(board[nx][ny] - 'A' == c - 'a'){
							board[nx][ny] = '.';
						}
					}
                }
                if('a' <= board[nx][ny] && board[nx][ny] <= 'z') {
                    key.push_back(board[nx][ny]);
                    board[nx][ny] = '.';
                    while(!Q.empty()) Q.pop();
                    for(auto nCur: start){
                        vis[nCur.first][nCur.second] = turn + 1;
                        Q.push({nCur.first, nCur.second, turn + 1});
                    }
                    break;
                }
                if(board[nx][ny] == '$'){
                    board[nx][ny] = '.';
                    ans++;
                }
                if(board[nx][ny] != '.' || vis[nx][ny] > turn) continue;
                vis[nx][ny] = turn + 1;
                Q.push({nx, ny, turn});
            }
        }
		cout << ans << '\n';
	}
	return 0;
}



/*
    열쇠로 문따기

    input:
        tc => test case
        h, w => 맵 ( 2 <= w, h <= 100 )
        배열
        key => 가지고 있는 열쇠
    output:
        ans => 최대 문서 획득 수
*/
