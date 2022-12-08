/*
? 문제 : 16165번 걸그룹 마스터 준석이
! 등급 : 실버 3
* 링크 : https://www.acmicpc.net/problem/16165
*/
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int groups_num, problems_num;
    unordered_map<string, vector<string>> list_group_name;
    unordered_map<string, string> list_name_group;
    cin >> groups_num >> problems_num;
    while (groups_num--) {
        string group;
        int members_num;
        cin >> group;
        cin >> members_num;
        while (members_num--) {
            string name;
            cin >> name;
            list_group_name[group].push_back(name);
            list_name_group.insert(make_pair(name, group));
        }
    }
    while (problems_num--) {
        string query;
        int type;
        cin >> query;
        cin >> type;
        if (type) {
            cout << list_name_group.find(query)->second << '\n';
        } else {
            sort(list_group_name[query].begin(), list_group_name[query].end());
            for (auto member : list_group_name[query]) {
                cout << member << '\n';
            }
        }
    }

    return 0;
}

/*
* MEMO *


*/
