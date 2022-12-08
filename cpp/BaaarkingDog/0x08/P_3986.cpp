/*
문제 : 3986번 좋은 단어
등급 : 실버 4
링크 : https://www.acmicpc.net/problem/3986
*/
#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, ans = 0;
    cin >> n;
    while(n--){
        stack<char> t;
        string s;
        cin >> s;
        for(auto c: s){
            if(!t.empty() && c ==  t.top()){
                t.pop();
            } else {
                t.push(c);
            }
        }
        if(t.empty()) ans++;
    }
    cout << ans << '\n';
    return 0;
}

/*
    좋은 단어란?
    평석이: 단어 위로 아치형 곡선을 그어 같은 글자끼리 쌍을 지을 때 선끼리 교차하지 않으면서 각 글자를 정확히 한 개의
            다른 위치에 있는 같은 글자와 짝 지을 수 있다면, 그 단어는 '좋은 단어'입니다.
    input:
        n => ( 1 <= n <= 100)
        s => ( 2 <= length <= 100,000 )
    output:
        ans => 좋은 단어의 수
*/
