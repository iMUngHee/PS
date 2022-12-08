/*
? 문제 : 2295번 세 수의 합
! 등급 : 골드 4
* 링크 : https://www.acmicpc.net/problem/2295
*/
#include <algorithm>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  vector<int> numbers;
  unordered_set<int> permutation_set;

  int N = 0;
  cin >> N;
  while (N--) {
    int number = 0;
    cin >> number;
    numbers.push_back(number);
  }

  for (auto n : numbers) {
    for (auto m : numbers) {
      permutation_set.insert(n + m);
    }
  }

  sort(numbers.begin(), numbers.end(),
       [](int& a, int& b) -> bool { return a > b; });

  for (int i = 0; i < numbers.size(); i++) {
    for (int j = i + 1; j < numbers.size(); j++) {
      if (permutation_set.count(numbers.at(i) - numbers.at(j))) {
        cout << numbers.at(i) << '\n';
        return 0;
      }
    }
  }

  return 0;
}

/*
* MEMO *


*/
