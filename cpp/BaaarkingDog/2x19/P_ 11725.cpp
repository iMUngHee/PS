/*
? 문제 : 11725번 트리의 부모 찾기
! 등급 : 실버 2
* 링크 : https://www.acmicpc.net/problem/11725
*/
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> adj[100001];
int p[100001];

void dfs(int cur) {
  for (int nxt : adj[cur]) {
    if (p[cur] == nxt) continue;
    p[nxt] = cur;
    dfs(nxt);
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  dfs(1);
  for (int i = 2; i <= n; i++) cout << p[i] << '\n';

  return 0;
}

/*
* MEMO *


*/
