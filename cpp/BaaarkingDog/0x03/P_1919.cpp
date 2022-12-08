/*
문제 : 1919번 애너그램 만들기
등급 : 브론즈 2
링크 : https://www.acmicpc.net/problem/1919
*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int alpha_s[26] = {0};
    int alpha_t[26] = {0};
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for(auto c: s){
        alpha_s[c - 'a']++;
    }
    for(auto c: t){
        alpha_t[c - 'a']++;
    } 
    for(int i = 0; i < 26; i++){
        if(alpha_s[i] != alpha_t[i]){
            if(alpha_s[i] > alpha_t[i])
                ans += alpha_s[i] - alpha_t[i];
            else
                ans += alpha_t[i] - alpha_s[i];
        }
    }
    cout << ans << '\n';
    return 0;
}
