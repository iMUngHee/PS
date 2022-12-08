/*
문제 : 2752번 세수 정렬
등급 : 브론즈 4
링크 : https://www.acmicpc.net/problem/2752
*/
#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int a[3] = {0};
    cin >> a[0] >> a[1] >> a[2];
    sort(a, a + 3);
    for (int i = 0; i < 3; i++)
        cout << a[i] << ' ';
    cout << '\n';
    return 0;
}