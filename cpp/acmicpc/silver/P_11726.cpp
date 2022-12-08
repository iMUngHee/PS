/*
? 문제 : P_11726번 2xn 타일링
! 등급 : 실버 3
* 링크 : https://www.acmicpc.net/problem/P_11726
*/
#include <iostream>
using namespace std;

const int MOD = 10007;
int dp[1002];

int solution(int k) {
  if (dp[k]) return dp[k];
  if (k == 1) return 1;
  if (k == 2) return 2;

  return dp[k] = (solution(k - 1) + solution(k - 2)) % MOD;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  cin >> n;

  cout << solution(n) << '\n';
  return 0;
}

/*
* MEMO *


*/
