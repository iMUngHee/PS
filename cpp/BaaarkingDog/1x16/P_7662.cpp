/*
? 문제 : 7662번 이중 우선순위 큐
! 등급 : 골드 4
* 링크 : https://www.acmicpc.net/problem/7662
*/
#include <iostream>
#include <set>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int tc = 0;
  cin >> tc;

  while (tc--) {
    int k = 0;
    multiset<int> nums_list;
    cin >> k;

    while (k--) {
      char query;
      int n = 0;
      cin >> query >> n;
      if (query == 'I') {
        nums_list.insert(n);
      }
      if (query == 'D' && nums_list.empty()) {
        continue;
      } else if (query == 'D' && n == 1) {
        nums_list.erase(prev(nums_list.end()));
      } else if (query == 'D' && n == -1) {
        nums_list.erase(nums_list.begin());
      }
    }

    if (nums_list.empty())
      cout << "EMPTY" << '\n';
    else
      cout << *prev(nums_list.end()) << ' ' << *nums_list.begin() << '\n';
  }

  return 0;
}

/*
* MEMO *


*/
