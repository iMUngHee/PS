/*
? 문제 : 11478번 서로 다른 부분 문자열의 개수
! 등급 : 실버 3
* 링크 : https://www.acmicpc.net/problem/11478
*/
#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    unordered_set<string> str_set;
    cin >> str;
    for (int i = 0; i < str.size(); i++) {
        string temp = "";
        for (int j = i; j < str.size(); j++) {
            temp += str.at(j);
            if (str_set.count(temp)) continue;
            str_set.insert(temp);
        }
    }

    cout << str_set.size() << '\n';

    return 0;
}

/*
* MEMO *


*/
