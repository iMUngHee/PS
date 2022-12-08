/*
문제 : 5397번 키로거
등급 : 실버 3
링크 : https://www.acmicpc.net/problem/5397
*/
#include <iostream>
#include <list>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        string str;
        list<char> password = {};
        cin >> str;
        auto cursor = password.begin();
        for(auto c: str){
            if(c == '-'){
                if(cursor != password.begin()){
                    cursor--;
                    cursor = password.erase(cursor);
                }
            } else if(c == '<'){
                if(cursor != password.begin()){
                    cursor--;
                }
            } else if(c == '>'){
                if(cursor != password.end()){
                    cursor++;
                }
            } else{
                password.insert(cursor, c);
            }
        }
        for(auto c: password) cout << c;
        cout << '\n';
    }
    return 0;
}

/*
    입력 가능한 키 : 알파벳 대문자, 소문자, 숫자, 백스페이스 화살표
    입력:
        tc => TestCase
        str => 길이가 L(1 <= L <= 1,000,000)인 문자열
            -: 백스페이스, 문자 지움 / <, >: 화살표, 왼쪽 오른쪽 커서 움직임

*/