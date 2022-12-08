/*
문제 : 5430번 AC
등급 : 골드 5
링크 : https://www.acmicpc.net/problem/5430
*/
#include <algorithm>
#include <deque>
#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while (tc--) {
        deque<int> d;
        string p;
        int n;
        string x;
        cin >> p;
        cin >> n;
        cin >> x;
        // parsing
        int tmp = 0;
        for (char c : x) {
            if (c != '[' && c != ']') {
                if (c == ',') {
                    d.push_back(tmp);
                    tmp = 0;
                } else
                    tmp = tmp * 10 + (c - '0');
            }
        }
        if (tmp != 0) d.push_back(tmp);
        // query
        bool head = true;
        bool error = false;
        for (char c : p) {
            if (c == 'R') {
                head = !head;
            } else {
                if (d.empty()) {
                    error = true;
                    break;
                }
                if (head)
                    d.pop_front();
                else
                    d.pop_back();
            }
        }
        // error print
        if (error) {
            cout << "error" << '\n';
            continue;
        }
        // print
        cout << '[';
        if (!head) {
            reverse(d.begin(), d.end());
        }
        for (int i = 0; i < d.size(); i++) {
            cout << d[i];
            // 시발 틀렸던 부분 => if (i != d.back()) cout << ',';
            if (i + 1 != d.size()) cout << ',';
        }
        cout << ']' << '\n';
    }
    return 0;
}

/*
    R - reverse
    d - delete / if empty : error
    input:
    tc => 1 <= tc <= 100
    p => string: 1 <= len <= 100,000
    n => size of array: 0 <= n <= 100,000
    [x1, ... , xn] => 1 <= xi <= 100
*/
