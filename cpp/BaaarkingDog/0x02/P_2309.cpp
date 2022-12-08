/*
문제 : 2309번 일곱 난쟁이
등급 : 브론즈 2
링크 : https://www.acmicpc.net/problem/2309
*/
#include <algorithm>
#include <iostream>

using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int arr[9] = {0};
    int sum = 0;
    int spy_1 = 0, spy_2 = 0;
    for (int i = 0; i < 9; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + 9);
    for (int i = 0; i < 8; i++) {
        for (int j = i + 1; j < 9; j++) {
            if (sum - arr[i] - arr[j] == 100) {
                spy_1 = arr[i];
                spy_2 = arr[j];
                break;
            }
        }
    }
    for (int i = 0; i < 9; i++) {
        if (arr[i] != spy_1 && arr[i] != spy_2) {
            cout << arr[i] << '\n';
        }
    }
    return 0;
}