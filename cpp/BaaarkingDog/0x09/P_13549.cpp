/*
문제 : 13549번 숨바꼭질 3
등급 : 골드 5
링크 : https://www.acmicpc.net/problem/13549
*/
#include <iostream>
#include <deque>

#define X first
#define Y second

using namespace std;

int board[100002];
int dist[200002];

deque<int> Q;

int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    fill(dist, dist + 200002, -1);
    dist[n] = 0;
    Q.push_back(n);
    while(!Q.empty()){
        int cur = Q.front(); Q.pop_front();
        // cout << "NOW: " << cur << ", DIST: " << dist[cur] << '\n';
        if(cur == k){
            cout << dist[cur] << '\n';
            return 0;
        }
        if(2 * cur < 200002 && dist[2 * cur] == -1){
            dist[2*cur] = dist[cur];
            Q.push_front(2*cur);
        }
        for(int dir: {1, -1}){
            int nx = cur;
            if(dir == 2) nx *= dir;
            else nx += dir;
            if(nx < 0 or nx >= 200002) continue;
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[cur] + 1;
            Q.push_back(nx);
        }
    }
    return 0;
}

/*
    <---!!! 순간이동하면 dist값이 안올라가니까 큐에 넣을 때 맨 앞에 넣어줘야함 !!!--->
    동생 찾기
    1초 x - 1, x + 1
    0초 2 * x
    input:
        n => 수빈 위치 ( 0 <= n <= 100,000 )
        k => 동생 위치 ( 0 <= k <= 100,000 )
    output:
        ans => 최초 발견 시간
*/
