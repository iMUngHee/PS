/*
? 문제 : 1786번 찾기
! 등급 : 플래티넘 5
* 링크 : https://www.acmicpc.net/problem/1786
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
  getline(cin, s);
  getline(cin, p);

  vector<int> f = failure(p);
  vector<int> index_list;

  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    while (j > 0 && s[i] != p[j]) j = f[j - 1];
    if (s[i] == p[j]) j++;
    if (j == p.size()) {
      index_list.push_back(i - p.size() + 2);
      j = 0;
    }
  }

  cout << index_list.size() << '\n';
  if (index_list.size()) {
    for (auto v : index_list) {
      cout << v << ' ';
    }
    cout << '\n';
  }

  return 0;
}

/*
* MEMO *
⭐️ getline

*/
