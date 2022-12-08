/*
문제 : 2446번 별 찍기 - 9
등급 : 브론즈 3
링크 : https://www.acmicpc.net/problem/2446
*/
#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < i; j++)
            cout << ' ';
        for (int j = 0; j < 2 * (N - i) - 1; j++)
            cout << '*';
        cout << "\n";
    }
    for (int j = 0; j < N - 1; j++)
        cout << ' ';
    cout << "*\n";
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= N - i - 1; j++)
            cout << ' ';
        for (int j = 1; j <= 2 * i + 1; j++)
            cout << '*';
        cout << "\n";
    }
    return 0;
}