/*
? 문제 : 조세푸스 문제
! 등급 : 하
* 링크 : https://www.algospot.com/judge/problem/read/JOSEPHUS
*/
#include <iostream>
#include <list>

using namespace std;

int tc;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> tc;
    while (tc--) {
        list<int> survivors;
        int members = 0, interval = 0;
        cin >> members >> interval;

        for (int i = 1; i <= members; i++) survivors.push_back(i);

        list<int>::iterator kill = survivors.begin();
        while (members > 2) {
            kill = survivors.erase(kill);
            members--;
            if (kill == survivors.end()) kill = survivors.begin();

            for (int i = 0; i < interval - 1; i++) {
                ++kill;
                if (kill == survivors.end()) kill = survivors.begin();
            }
        }

        for (auto &&i : survivors) {
            cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}

/*
* Memo *

*/
