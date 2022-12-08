/*
? 문제 : 짝이 맞지 않는 괄호
! 등급 : 하
* 링크 : https://www.algospot.com/judge/problem/read/BRACKETS2
*/
#include <iostream>
#include <stack>

using namespace std;

const string YES = "YES";
const string NO = "NO";

int tc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tc;

    while (tc--) {
        stack<char> checker;
        string brackets;
        bool earlyStop = false;
        cin >> brackets;

        for (auto &&b : brackets) {
            if (b == '[' or b == '{' or b == '(')
                checker.push(b);
            else if (!checker.empty()) {
                if (b == ']' and checker.top() == '[')
                    checker.pop();
                else if (b == '}' and checker.top() == '{')
                    checker.pop();
                else if (b == ')' and checker.top() == '(')
                    checker.pop();
            } else {
                earlyStop = true;
                break;
            }
        }

        if (!checker.empty() || earlyStop)
            cout << NO << '\n';
        else
            cout << YES << '\n';
    }

    return 0;
}

/*
* MEMO *


*/
