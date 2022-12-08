/*
문제 : 1267번 휴대폰 요금
등급 : 브론즈 3
링크 : https://www.acmicpc.net/problem/1267
*/
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 0;
    cin >> tc;
    int y = 0, m = 0;
    while(tc--){
        int fee = 0;
        cin >> fee;
        y += (fee / 30 ) * 10 + 10;
        m += (fee / 60 ) * 15 + 15;
    }
    if(y > m){
        cout << 'M' << ' ' << m << '\n';
    }else if ( m > y){
        cout << 'Y' << ' ' << y << '\n';
    }else{
        cout << 'Y' << ' ' << 'M' << ' ' << m << '\n';
    }
    return 0;
}