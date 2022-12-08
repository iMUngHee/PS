/*
? 문제 : 13414번 수강신청
! 등급 : 실버 3
* 링크 : https://www.acmicpc.net/problem/13414
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int limit = 0, list_len = 0;
    unordered_map<string, int> clicked_list;

    cin >> limit >> list_len;

    int rank = 0;
    while (list_len--) {
        string id;
        cin >> id;
        if (clicked_list.count(id)) {
            clicked_list.erase(clicked_list.find(id));
        }
        clicked_list.insert({id, ++rank});
    }

    vector<pair<string, int>> wait_list(clicked_list.begin(),
                                        clicked_list.end());
    sort(wait_list.begin(), wait_list.end(),
         [](pair<string, int> &a, pair<string, int> &b) -> bool {
             return a.second < b.second;
         });

    int print_num = limit < wait_list.size() ? limit : wait_list.size();
    for (int i = 0; i < print_num; i++) {
        cout << wait_list.at(i).first << '\n';
    }

    return 0;
}

/*
* MEMO *
⭐️ lambda function
⭐️ function pointer
⭐️ function class
⭐️ sort_comp
*/
