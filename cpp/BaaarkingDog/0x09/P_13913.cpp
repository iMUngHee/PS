/*
문제 : 13913번 숨바꼭질 4
등급 : 골드 4
링크 : https://www.acmicpc.net/problem/13913
*/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dist[100002];
int prePos[1000002];
queue<int> Q;
vector<int> V;
int n, k;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    fill(dist, dist + 100002, -1);
    dist[n] = 0;
    Q.push(n);
    while(!Q.empty()){
        int cur = Q.front();
        Q.pop();
        // cout << "Dist: " << dist[cur] << ", Now: " << cur << '\n';
        if(cur == k){
            cout << dist[k] << '\n';
            int tmp = cur;
            while(tmp != n){
                V.push_back(tmp);
                tmp = prePos[tmp];
            }
            V.push_back(tmp);
            while(!V.empty()){
                int tr = V.back();
                V.pop_back();
                cout << tr << ' ';
            }
            cout << '\n';
            return 0;
        }
        for(int nx: {cur - 1, cur + 1, 2 * cur}){
            if(nx < 0 or nx >= 100002) continue;
            if(dist[nx] >= 0) continue;
            dist[nx] = dist[cur] + 1;
            prePos[nx] = cur;
            Q.push(nx);
        }
    }
    return 0;
}

/*
    <--- vector를 써서 경로를 저장하면 10만 1개의 요소를 답도 없이 넣어야되서 시간 초과남 --->
    동생 찾기
    1초 후 X-1, X+1, 2*X로 이동
    최소 시간과 경로 출력
    input:
        n, k => 동생과 수빈이 위치 0 <= n, k <= 100,000
    output:
        ans => 최소 시간
        경로 => 최소 루트로 찾기까지의 경로
*/
