/*
문제 : 2445번 별 찍기 - 8
등급 : 브론즈 3
링크 : https://www.acmicpc.net/problem/2445
*/
#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= i; j++)
            cout << '*';
        for (int j = 1; j <= 2 * (N - i); j++)
            cout << ' ';
        for (int j = 1; j <= i; j++)
            cout << '*';
        cout << "\n";
    }
    for (int j = 1; j <= 2 * N; j++)
        cout << '*';
    cout << "\n";
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= N - i; j++)
            cout << '*';
        for (int j = 1; j <= 2 * i; j++)
            cout << ' ';
        for (int j = 1; j <= N - i; j++)
            cout << '*';
        cout << "\n";
    }
    return 0;
}