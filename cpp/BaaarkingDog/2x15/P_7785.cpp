/*
? 문제 : 7785번 회사에 있는 사람
! 등급 : 실버 5
* 링크 : https://www.acmicpc.net/problem/7785
*/
#include <algorithm>
#include <iostream>
//! <unordered_set>
#include <unordered_set>
#include <vector>

#define ENTER "enter"
#define LEAVE "leave"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    unordered_set<string> list_of_entered;
    int number_of_members = 0;

    cin >> number_of_members;
    while (number_of_members--) {
        string name, cmd;
        cin >> name >> cmd;
        if (cmd == ENTER) {
            list_of_entered.insert(name);
        } else if (cmd == LEAVE && list_of_entered.count(name)) {
            list_of_entered.erase(name);
        }
    }

    //! C++ Instance 생성 시 초기화
    vector<string> sorted_list_of_entered(list_of_entered.begin(),
                                          list_of_entered.end());
    //! std:greater
    sort(sorted_list_of_entered.begin(), sorted_list_of_entered.end(),
         greater<string>());

    for (auto member : sorted_list_of_entered) {
        cout << member << '\n';
    }

    return 0;
}

/*
* MEMO *
⭐️ <unordered_set>
⭐️ C++ Instance 생성 시 초기화
⭐️ std:greater
*/
