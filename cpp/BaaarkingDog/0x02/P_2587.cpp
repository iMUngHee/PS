/*
문제 : 2587번 대표값 2
등급 : 브론즈 2
링크 : https://www.acmicpc.net/problem/2587
*/
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int avg = 0, mid = 0;
    int arr[10] = {0};
    for(int i = 0; i < 5; i++){
        int n = 0;
        cin >> n;
        avg += n;
        arr[(n / 10) - 1]++;
    }
    avg /= 5;
    for(int i = 0; i < 10; i++){
        mid += arr[i];
        if(mid >= 3){
            mid = (i + 1) * 10;
            break;
        }
    }
    cout << avg << '\n';
    cout << mid << '\n';
    return 0;
}