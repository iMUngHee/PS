/*
문제 : 10799번 쇠막대기
등급 : 실버 3
링크 : https://www.acmicpc.net/problem/10799
*/
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ans = 0;
    char prev = 0;
    stack<char> t;
    string s;
    cin >> s;
    for(char c: s){
        if(t.empty()) t.push(c);
        else if(prev == '(' && c == ')'){
            t.pop();
            ans += t.size();
        } else if(t.top() == '(' && c == ')'){
            t.pop();
            ans++;
        } else {
            t.push(c);
        }
        prev = c;
    }
    cout << ans << '\n';
    return 0;
}

/*
    쇠막대 절단
    조건
    1. 쇠막대기는 자신보다 긴 막대기 위에만 놓임. 완전히 포함되도록 놓되, 끝점은 겹치지 않음.
    2. 레이저는 적어도 하나 존재
    3. 레이저는 어떤 쇠막대기의 양 끝점과도 겹치지 않음.
    ---
    표현
    1. 레이저는 인접한 괄호 쌍 '()'으로 표현. 모든 '()'는 반드시 레이저를 표현
    2. 쇠막대기의 왼쪽 끝은 여는 괄호 '(', 오른쪽 끝은 닫힌 괄호 ')'로 표현
    
    input:
        s => (1 <= length <= 100,000)
    output:
        ans => 잘려진 조각의 총 개수
    
    ----
    3 + 3 + 1 + 3 + 1 + 2 + 1 + 1 + 1 + 1 = 17
    (((... 스택 쌓다가 인접된 () 만나면 사이즈만큼 쁠라스 / 쌍은 팝! !important
    떨어진 () 만나면 1만큼 쁠라스 / 쌍은 팝!
*/
