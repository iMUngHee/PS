/*
? 문제 : 16916번 부분 문자열
! 등급 : 브론즈 2
* 링크 : https://www.acmicpc.net/problem/16916
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
  cin >> s >> p;
  vector<int> f = failure(p);
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    while (j > 0 && s[i] != p[j]) j = f[j - 1];
    if (s[i] == p[j]) j++;
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
