/*
문제 : 10808번 알파벳 개수
등급 : 브론즈 2
링크 : https://www.acmicpc.net/problem/10808
*/
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int ans[26] = {0};
    while(1){
        char a;
        cin.get(a);
        if(a == '\n') break;
        ans[a - 'a']++;
    }
    /*
    string s;
    cin >> s;
    for(auto c : s) ans[c - 'a']++;
    */
    for(int i = 0; i < 26; i++) cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}

/**
 *  cin.get() 
 *  => <iostream> 에 존재
 *  => 표준 입력 버퍼에서 문자를 하나만 가져옴
 *  => 공백, 개행 포함
 *  => 문자만 입력 받음
*/