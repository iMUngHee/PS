/*
문제 : 10804번 카드 역배치
등급 : 브론즈 2
링크 : https://www.acmicpc.net/problem/10804
*/
#include <iostream>
using namespace std;

int card[20] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10,
                11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

void suffle(int a, int b) {
    int tmp[21] = { 0 };
    for (int i = 0; i < b - a + 1; i++) {
        tmp[i] = card[b - 1 - i];
    }
    for (int i = 0; i < b - a + 1; i++) {
        card[a - 1 + i] = tmp[i];
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    for (int i = 0; i < 10; i++) {
        int a, b;
        cin >> a >> b;
        suffle(a, b);
    }
    for (int i = 0; i < 20; i++)
        cout << card[i] << ' ';
    cout << '\n';
    return 0;
}