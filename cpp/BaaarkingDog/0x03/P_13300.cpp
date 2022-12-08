/*
문제 : 13300번 방 배정
등급 : 브론즈 2
링크 : https://www.acmicpc.net/problem/13300
*/
#include <iostream>
using namespace std;

int arr[12];  // gender * grade => 2 * 6

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int num = 0, limit = 0;
    cin >> num >> limit;
    for(int i = 0; i < num; i++){
        int gender = 0, grade = 0;
        cin >> gender >> grade;
        gender ? arr[grade - 1]++ : arr[grade + 6 - 1]++;
    }
    int ans = 0;
    for(int i = 0; i < 12; i++){
        if(arr[i] % limit != 0) ans += arr[i] / limit + 1;
        else ans += arr[i] / limit;
    }
    cout << ans << '\n';
    return 0;
}

/*
    female : 1 / 2 / 3 / 4 / 5 / 6
    male : 7 / 8 / 9 / 10 / 11 / 12
    1 <= N <= 1000
    1 <= K <= 1000
    학년 분리
    남, 녀 분리
    한 방엔 최대 k명 배정 가능
    ----
    한 방에 한 명만 배정도 가능
*/