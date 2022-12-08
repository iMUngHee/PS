/*
문제 : 2444번 별 찍기 - 7
등급 : 브론즈 3
링크 : https://www.acmicpc.net/problem/2444
*/
#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N - 1; i++) {
        for (int j = 1; j <= N - i; j++)
            cout << ' ';
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << '*';
        cout << "\n";
    }
    for (int j = 1; j <= 2 * N - 1; j++)
        cout << '*';
    cout << "\n";
    for (int i = N - 1; i >= 1; i--) {
        for (int j = 1; j <= N - i; j++)
            cout << ' ';
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << '*';
        cout << "\n";
    }
    return 0;
}