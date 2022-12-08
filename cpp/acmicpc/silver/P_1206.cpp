/*
? 문제 : 1206번 DFS와 BFS
! 등급 : 실버 2
* 링크 : https://www.acmicpc.net/problem/1206
*/
#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int vertex_num, edge_num, start;
  int bfs_vis[1002];
  int dfs_vis[1002];
  vector<int> adj[1002];
  stack<int> S;
  queue<int> Q;

  memset(bfs_vis, 0, sizeof(bfs_vis));
  memset(dfs_vis, 0, sizeof(dfs_vis));
  cin >> vertex_num >> edge_num >> start;

  while (edge_num--) {
    int from, to;
    cin >> from >> to;
    adj[from].push_back(to);
    adj[to].push_back(from);
  }

  // DFS
  for (vector<int> &node : adj)
    sort(node.begin(), node.end(),
         [](int &a, int &b) -> bool { return a > b; });
  S.push(start);
  while (!S.empty()) {
    int cur = S.top();
    S.pop();
    if (dfs_vis[cur]) continue;
    dfs_vis[cur] = 1;
    cout << cur << ' ';
    for (int nxt : adj[cur]) {
      if (dfs_vis[nxt]) continue;
      S.push(nxt);
    }
  }
  cout << '\n';

  // BFS
  for (vector<int> &node : adj)
    sort(node.begin(), node.end(),
         [](int &a, int &b) -> bool { return a < b; });
  Q.push(start);
  bfs_vis[start] = 1;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();
    cout << cur << ' ';
    for (int nxt : adj[cur]) {
      if (bfs_vis[nxt]) continue;
      bfs_vis[nxt] = 1;
      Q.push(nxt);
    }
  }
  cout << '\n';

  return 0;
}

/*
* MEMO *


*/
