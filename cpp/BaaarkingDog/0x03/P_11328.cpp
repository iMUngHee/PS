/*
문제 : 11328번 Strfry
등급 : 브론즈 2
링크 : https://www.acmicpc.net/problem/11328
*/
#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        int alpha_s[26] = {0};
        int alpha_t[26] = {0};
        bool pos = true;
        string s, t;
        cin >> s >> t;
        for(auto c: s){
            alpha_s[c - 'a']++;
        }
        for(auto c: t){
            alpha_t[c - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(alpha_s[i] != alpha_t[i]) pos = false;
        }
        if(pos) cout << "Possible" << '\n';
        else cout << "Impossible" << '\n';
    }
    return 0;
}
