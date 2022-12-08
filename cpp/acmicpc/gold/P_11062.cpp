/*
? 문제 : 11062번 카드 게임
! 등급 : 골드 3
* 링크 : https://www.acmicpc.net/problem/11062
*/
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

int dp[1002][1002][2];
int card[1002];

int solve(int left, int right, int turn) {
  int &ret = dp[left][right][turn];
  if (ret != -1) return ret;
  if (left >= right) {
    if (!turn)
      return ret = card[left];
    else
      return ret = 0;
  }
  if (!turn) {
    return ret = max(solve(left + 1, right, !turn) + card[left],
                     solve(left, right - 1, !turn) + card[right]);
  } else {
    return ret = min(solve(left + 1, right, !turn),
                     solve(left, right - 1, !turn));
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tc;
  cin >> tc;
  while (tc--) {
    memset(dp, -1, sizeof(dp));
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> card[i];

    cout << solve(0, n - 1, 0) << '\n';
  }

  return 0;
}

/*
* MEMO *


*/
