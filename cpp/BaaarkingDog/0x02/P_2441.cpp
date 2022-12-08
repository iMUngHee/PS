/*
문제 : 2441번 별 찍기 - 4
등급 : 브론즈 3
링크 : https://www.acmicpc.net/problem/2441
*/
#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        int j = 0;
        for (; j < i; j++)
            cout << ' ';
        for (; j < N; j++)
            cout << '*';
        cout << "\n";
    }
}