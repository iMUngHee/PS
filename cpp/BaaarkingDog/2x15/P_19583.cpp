/*
? 문제 : 19583번 싸이버개강총회
! 등급 : 실버 2
* 링크 : https://www.acmicpc.net/problem/19583
*/
#include <iostream>
#include <unordered_set>
using namespace std;

int calculate_time(string time_str) {
    return stoi(time_str.substr(0, 2)) * 60 + stoi(time_str.substr(3, 4));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string start_time_str, end_time_str, quit_time_str;
    int start_time, end_time, quit_time;
    unordered_set<string> checked_set;
    cin >> start_time_str >> end_time_str >> quit_time_str;

    start_time = calculate_time(start_time_str);
    end_time = calculate_time(end_time_str);
    quit_time = calculate_time(quit_time_str);

    int ans = 0;
    while (!cin.eof()) {
        string time_str, name;
        cin >> time_str >> name;
        if (time_str.size() < 2) break;
        int time = calculate_time(time_str);
        if (time <= start_time && !checked_set.count(name)) {
            checked_set.insert(name);
        } else if (end_time <= time && time <= quit_time &&
                   checked_set.count(name)) {
            ans++;
            checked_set.erase(checked_set.find(name));
        }
    }

    cout << ans << '\n';

    return 0;
}

/*
* MEMO *


*/
