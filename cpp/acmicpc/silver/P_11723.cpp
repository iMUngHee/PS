/*
? 문제 : 11723번 집합
! 등급 : 실버 5
* 링크 : https://www.acmicpc.net/problem/11723
*/
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int cmd_num;
  unordered_set<int> store;
  cin >> cmd_num;

  while (cmd_num--) {
    string cmd;
    int val;
    cin >> cmd;

    if (cmd == "add") {
      cin >> val;
      store.insert(val);
    } else if (cmd == "remove") {
      cin >> val;
      if (store.count(val)) store.erase(val);
    } else if (cmd == "check") {
      cin >> val;
      cout << store.count(val) << '\n';
    } else if (cmd == "toggle") {
      cin >> val;
      if (store.count(val))
        store.erase(val);
      else
        store.insert(val);
    } else if (cmd == "all") {
      for (int i = 1; i <= 20; i++) store.insert(i);
    } else if (cmd == "empty") {
      for (int i = 1; i <= 20; i++) store.erase(i);
    }
  }

  return 0;
}

/*
* MEMO *


*/
