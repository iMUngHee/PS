/*
? 문제 : 2108번 통계학
! 등급 : 실버 3
* 링크 : https://www.acmicpc.net/problem/2108
*/
#include <algorithm>
#include <cmath>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> V;
    unordered_map<int, int> M;
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        V.push_back(tmp);
        if (M.count(tmp))
            M.find(tmp)->second++;
        else
            M.insert({tmp, 1});
    }

    sort(V.begin(), V.end());
    int sum = 0;
    for (auto num : V) sum += num;
    //* AVG
    int sign = sum > 0 ? 1 : -1;
    cout << (int)round(abs(sum) / (double)V.size()) * sign << '\n';

    //* MID
    cout << V.at(V.size() / 2) << '\n';

    //* FREQ
    if (V.size() > 1) {
        vector<pair<int, int>> sorted(M.begin(), M.end());
        sort(sorted.begin(), sorted.end(),
             [](pair<int, int> &a, pair<int, int> &b) -> bool {
                 if (a.second == b.second) return a.first < b.first;
                 return a.second > b.second;
             });
        if (sorted.at(0).second == sorted.at(1).second)
            cout << sorted.at(1).first << '\n';
        else
            cout << sorted.at(0).first << '\n';
    } else {
        cout << V.at(0) << '\n';
    }

    //* RANGE
    int min_num = 4001;
    int max_num = -4001;
    for (auto num : V) {
        if (num < min_num) min_num = num;
        if (num > max_num) max_num = num;
    }

    cout << max_num - min_num << '\n';

    return 0;
}

/*
* MEMO *


*/
