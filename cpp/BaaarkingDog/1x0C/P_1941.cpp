/*
문제 : 1941번 소문난 칠공주
등급 : 골드 3
링크 : https://www.acmicpc.net/problem/1941
*/
#include <iostream>
#include <queue>
#define X first
#define Y second

using namespace std;

string board[7];
int vis[7][7];

queue<pair<int,int>> Q;

bool isSelect[27];
int ans;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isAdjacent(){
    for(int i = 0; i < 5; i++)
        fill(vis[i], vis[i] + 5, 0);
    for(int i = 0; i < 25; i++){
        if(isSelect[i]){
            int x = i / 5, y = i % 5;
            vis[x][y] = 1;
            Q.push({x, y});
            break;
        }
    }
    int isSeven = 1;
    while(!Q.empty()){
        auto cur = Q.front(); Q.pop();
        for(int dir = 0; dir < 4; dir++){
            int nx = cur.X + dx[dir];
            int ny = cur.Y + dy[dir];
            if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if(!isSelect[nx * 5 + ny]) continue;
            if(vis[nx][ny]) continue;
            isSeven++;
            vis[nx][ny] = 1;
            Q.push({nx, ny});
        }
    }
    if(isSeven == 7) return true;
    else return false;
}

bool isMoreThanFour(){
    int numS = 0;
    for(int i = 0; i < 25; i++){
        if(isSelect[i]){
            int x = i / 5, y = i % 5;
            if(board[x][y] == 'S') numS++;
        }
    }
    if(numS > 3) return true;
    else return false;
}

void solve(int pos, int cnt){
    if(cnt == 7){
        if(isAdjacent())
            if(isMoreThanFour()) ans++;
        return;
    }
    for(int i = pos; i < 25; i++){
        if(!isSelect[i]){
            isSelect[i] = true;
            solve(i, cnt + 1);
            isSelect[i] = false;
        }
    }
    return;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 0; i < 5; i++){
        cin >> board[i];
    }
    solve(0, 0);
    cout << ans << '\n';
    return 0;
}

/**
 *  5 * 5 행렬
 *  Y => 임도'연'파 S => 이다'솜'파
 *  칠공주 조건 )
 *  1. 7명
 *  2. 서로 가로세로로 인접
 *  3. Y든 S든 상관 없음
 *  4. 단, S가 적어도 4명 이상은 반드시 포함. 
 *  
 *  Input:
 *      board => 5*5 행렬
 *  Output:
 *      ans => 칠공주 결성 경우의수
 */