/*
문제 : 1475번 방 번호
등급 : 실버 5
링크 : https://www.acmicpc.net/problem/1475
*/
#include <iostream>
using namespace std;

int num[9];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int room = 0;
    cin >> room;
    while(1){
        int tmp = room % 10;
        room /= 10;
        if(tmp == 9){ num[6]++;}  // 9 / 6 동일
        else num[tmp]++;
        if(!room) break;
    }
    num[6] -= num[6] / 2;
    int ans = -1;
    for(int i = 0; i < 9; i++){
        if(ans < num[i]) ans = num[i];
    }
    cout << ans << '\n';
    return 0;
}

/*
    0 ~ 9번까지 있음
    한 세트에는 0 ~ 9 하나 씩 들어있음
    9 / 6은 동일 취급
    9999 - 2세트만 있어도 됨
    9996
    9966
    9666 - 2세트만 있어도 됨
    6666
    
    69999

    99999/666666

    99666

    9 9 6 6 6 - 3세트 필요
*/