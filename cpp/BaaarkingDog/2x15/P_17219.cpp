/*
? 문제 : 17219번 비밀번호 찾기
! 등급 : 실버 4
* 링크 : https://www.acmicpc.net/problem/17219
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int address_num, query_num;
    unordered_map<string, string> store;
    cin >> address_num >> query_num;
    while (address_num--) {
        string address, password;
        cin >> address >> password;
        store.insert(make_pair(address, password));
    }
    while (query_num--) {
        string query;
        cin >> query;
        cout << store.find(query)->second << '\n';
    }

    return 0;
}

/*
* MEMO *


*/
