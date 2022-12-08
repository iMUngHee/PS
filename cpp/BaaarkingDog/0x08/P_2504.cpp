/*
문제 : 2504번 괄호의 값
등급 : 실버 2
링크 : https://www.acmicpc.net/problem/2504
*/
#include <iostream>
#include <stack>

using namespace std;

stack<char> t;
string s;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> s;
    int acc = 0;
    int num = 1;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            num *= 2;
            t.push(s[i]);
        } else if (s[i] == '[') {
            num *= 3;
            t.push(s[i]);
        } else if (s[i] == ')') {
            if (t.empty() || t.top() != '(') {
                cout << 0 << '\n';
                return 0;
            }
            if (s[i - 1] == '(') acc += num;
            t.pop();
            num /= 2;
        } else if (s[i] == ']') {
            if (t.empty() || t.top() != '[') {
                cout << 0 << '\n';
                return 0;
            }
            if (s[i - 1] == '[') acc += num;
            t.pop();
            num /= 3;
        }
    }
    if (t.empty())
        cout << acc << '\n';
    else
        cout << 0 << '\n';
    return 0;
}

/*
    1. 인접 '()' = 2
    2. 인접 '[]' = 3
    3. ( A ) => 2 * A
    4. [ A ] => 3 * A
    5. A B => A + B

    input:
        s => (1 <= s <= 30)
    output:
        ans => 계산한 값 / 입력 에러일 시 0 출력
*/
