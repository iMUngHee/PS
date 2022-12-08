/*
문제 : 3197번 백조의 호수
등급 : 플래티넘 5
링크 : https://www.acmicpc.net/problem/3197
*/
#include <iostream>
#include <queue>

#define X first
#define Y second

using namespace std;

char board[1502][1502];
int visS[1502][1502];
int distI[1502][1502];
queue<pair<int,int>> S;
queue<pair<int,int>> tmpS;
queue<pair<int,int>> I;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int r, c;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> r >> c;
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            cin >> board[i][j];
            if(board[i][j] == '.'){
                visS[i][j] = -1;
                I.push({i,j});
            }
            else if(board[i][j] == 'X'){
                distI[i][j] = -1;
            }
            else if(board[i][j] == 'L'){
                I.push({i,j});
                if(S.empty()){
                    visS[i][j] = -2;
                    S.push({i,j});
                }
            }
        }
    }
    while(!I.empty()){
        auto cur = I.front(); I.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
            if(distI[nx][ny] >= 0 ) continue;
            distI[nx][ny] = distI[cur.X][cur.Y] + 1;
            visS[nx][ny] = distI[nx][ny];
            I.push({nx,ny});
        }
    }
    int turn = 0;
    while(!S.empty()){
        auto cur = S.front(); S.pop();
        int x = cur.X;
        int y = cur.Y;
        for(int dir = 0; dir < 4; dir++){
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if(nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
            if(visS[nx][ny] > turn){
                tmpS.push({x,y});
                continue;
            }
            if(visS[nx][ny] < -1 ) continue;
            if(board[nx][ny] == 'L' && visS[nx][ny] == 0){
                cout << turn << '\n';
                return 0;
            }
            visS[nx][ny] = -2 ;
            S.push({nx, ny});
        }
        if(S.empty()){
            S = tmpS;
            turn++;
            while(!tmpS.empty()) tmpS.pop();
        }
    }
    return 0;
}

/*
    .은 물 X는 빙판
    빙판은 물과 접촉해 있으면 다음날 녹음
    L은 백조 항상 두 마리
    두 마리가 같은 구역에 있으면 종료
    input:
        r, c => 세로 가로 1 <= r, c <= 1500
        배열 => . 은 물, X는 빙판, L은 백조
    output:
        ans => 최소 일수
*/
