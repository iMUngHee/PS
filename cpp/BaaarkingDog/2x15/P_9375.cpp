/*
? 문제 : 9375번 패션왕 신해빈
! 등급 : 실버 3
* 링크 : https://www.acmicpc.net/problem/9375
*/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 0;
    cin >> tc;
    while (tc--) {
        int cloth_num = 0;
        unordered_map<string, int> cloth_map;
        cin >> cloth_num;
        while (cloth_num--) {
            string name, category;
            cin >> name >> category;
            if (!cloth_map.count(category)) {
                cloth_map[category] = 1;
            } else {
                cloth_map[category] += 1;
            }
        }

        int number_of_cases = 1;
        for (auto type : cloth_map) {
            number_of_cases *= type.second + 1;
        }

        cout << number_of_cases - 1 << '\n';
    }

    return 0;
}

/*
* MEMO *
⭐️ 조합론
*/
