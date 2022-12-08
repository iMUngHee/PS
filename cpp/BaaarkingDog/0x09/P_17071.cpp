/*
문제 : 17071번 숨바꼭질 5
등급 : 골드 1
링크 : https://www.acmicpc.net/problem/17071
*/
#include <iostream>
#include <tuple>
#include <queue>
#define MX 500000

using namespace std;

queue<tuple<int,int,int>> Q;
int vis[2][MX + 1];
int n, k;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	vis[0][n] = 1;
	Q.push({n, k, 0});
	while(!Q.empty()){
		auto cur = Q.front(); Q.pop();
		int sis, bro, acc;
		tie(sis, bro, acc) = cur;
		// cout << "NOW : " << sis << ", BRO: " << bro << ", ACC: " << acc - 1 << '\n'; 
		if(vis[acc % 2][bro]){
			cout << acc << '\n';
			return 0;
		}
		bro += ++acc;
		if(bro > MX) continue;
		for(int nxt: { sis + 1, sis - 1, sis * 2}){
			if(nxt < 0 || nxt > MX) continue;
			if(vis[acc % 2][nxt]) continue;
			vis[acc % 2][nxt] = 1;
			Q.push({nxt, bro, acc});
		}
	}
	cout << -1 << '\n';
	return 0;
}




/*
    마지막 동생 찾기
    수빈이는 X-1, X+1, 2*X 만큼 1초마다 움직임
    동생은 매초 이동을 하는데 처음 위치 K, 1초 후 K+1, 2초 후 K+1+2, ... n초후 K+1+2+...+n에 있음
    범위 밖 이동은 다메요
    input:
        n, k => 각 위치 0 <= n, k <= 500,000
    output:
        ans => 최소 시간
*/
