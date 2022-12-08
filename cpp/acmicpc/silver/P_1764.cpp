/*
? 문제 : 1764번 듣보잡
! 등급 : 실버 4
* 링크 : https://www.acmicpc.net/problem/1764
*/
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  unordered_set<string> list;
  int n, m;
  cin >> n >> m;
  while (n--) {
    string name;
    cin >> name;
    list.insert(name);
  }

  vector<string> answer;
  while (m--) {
    string name;
    cin >> name;
    if (list.count(name)) answer.push_back(name);
  }

  sort(answer.begin(), answer.end());
  cout << answer.size() << '\n';
  for (string name : answer) {
    cout << name << '\n';
  }

  return 0;
}

/*
* MEMO *


*/
