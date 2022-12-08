/*
문제 : 2442번 별 찍기 - 5
등급 : 브론즈 3
링크 : https://www.acmicpc.net/problem/2442
*/
#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N - i; j++)
            cout << ' ';
        for (int j = 1; j <= 2 * i - 1; j++)
            cout << '*';
        cout << "\n";
    }
}