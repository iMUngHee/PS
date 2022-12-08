/*
? 문제 : 1620번 나는야 포켓몬 마스터 이다솜
! 등급 : 실버 4
* 링크 : https://www.acmicpc.net/problem/1620
*/
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int monster_num = 0, problem_num = 0;
    int index = 1;
    unordered_map<string, int> list_monster_index;
    unordered_map<int, string> list_index_monster;

    cin >> monster_num >> problem_num;

    while (monster_num--) {
        string name;
        cin >> name;
        list_monster_index.insert(make_pair(name, index));
        list_index_monster.insert(make_pair(index++, name));
    }

    while (problem_num--) {
        string problem;
        cin >> problem;
        if (!isdigit(problem.front())) {
            cout << list_monster_index.find(problem)->second << '\n';
        } else {
            cout << list_index_monster.find(stoi(problem))->second << '\n';
        }
    }

    return 0;
}

/*
* MEMO *
⭐️ <unordered_map>
⭐️ isdigit
⭐️ 화살표 포인터
*/
