/*
문제 : 1021번 회전하는 큐
등급 : 실버 4
링크 : https://www.acmicpc.net/problem/1021
*/
#include <iostream>
#include <deque>

using namespace std;

deque<int> d;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, ans = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        d.push_back(i);
    }
    while(m--){
        int c;
        cin >> c;
        if(d.front() == c){
            d.pop_front();
            continue;
        }
        int idx = 0;
        for(auto a: d){
            if(a == c) break;
            else idx++;
        }
        if(d.size() / 2 < idx){
            
            while(d.front() != c){
                d.push_front(d.back());
                d.pop_back();
                ans++;
            }
        } else {
            while(d.front() != c){
                d.push_back(d.front());
                d.pop_front();
                ans++;
            }
        }
        d.pop_front();
    }
    cout << ans << '\n';
    return 0;
}

/*
    | ------- | ------- |
    1 9 | 12 13 14
    input:
        1 <= m <= n <= 50
    output:
        ans
*/
