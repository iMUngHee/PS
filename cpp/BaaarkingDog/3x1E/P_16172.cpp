/*
? 문제 : 16172번 나는 친구가 적다 (Large)
! 등급 : 브론즈 2
* 링크 : https://www.acmicpc.net/problem/16172
*/
#include <iostream>
#include <vector>
using namespace std;

vector<int> failure(string& s) {
  vector<int> f(s.size());
  int j = 0;
  for (int i = 1; i < s.size(); i++) {
    while (j > 0 && s[i] != s[j]) j = f[j - 1];
    if (s[i] == s[j]) f[i] = ++j;
  }

  return f;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  string s, p;
  string filtered = "";
  cin >> s >> p;

  for (auto c : s) {
    if (c >= '0' and c <= '9') continue;
    filtered += c;
  }

  vector<int> f = failure(p);
  int j = 0;
  for (int i = 0; i < filtered.size(); i++) {
    while (j > 0 && filtered[i] != p[j]) j = f[j - 1];
    if (filtered[i] == p[j]) j++;
    if (j == p.size()) {
      cout << 1;
      return 0;
    }
  }
  cout << 0;

  return 0;
}

/*
* MEMO *


*/
