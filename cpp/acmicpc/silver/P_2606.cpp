/*
? 문제 : 2606번 바이러스
! 등급 : 실버 3
* 링크 : https://www.acmicpc.net/problem/2606
*/
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int answer = 0;
  int computer_num, pair_num;
  int vis[102];
  vector<int> computer[102];
  memset(vis, 0, sizeof(vis));
  cin >> computer_num >> pair_num;

  while (pair_num--) {
    int from, to;
    cin >> from >> to;
    computer[from].push_back(to);
    computer[to].push_back(from);
  }

  queue<int> Q;

  Q.push(1);
  vis[1] = 1;

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (int child : computer[cur]) {
      if (vis[child]) continue;
      answer += 1;
      vis[child] = 1;
      Q.push(child);
    }
  }

  cout << answer << '\n';

  return 0;
}

/*
* MEMO *


*/
