/*
문제 : 2440번 별 찍기 - 3
등급 : 브론즈 3
링크 : https://www.acmicpc.net/problem/2440
*/
#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N - i; j++)
            cout << '*';
        cout << "\n";
    }
    return 0;
}