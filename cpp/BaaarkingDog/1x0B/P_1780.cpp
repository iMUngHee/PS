/*
문제 : 1780번 종이의 개수
등급 :  실버 2
링크 : https://www.acmicpc.net/problem/1780
*/
#include <iostream>

using namespace std;

int n;
int arr[2190][2190];
int cnt[3];

bool checker(int num, int col, int row){
    for(int i = col; i < col + num; i++){
        for(int j = row; j < row + num; j++){
            if(arr[col][row] != arr[i][j]) return false;
        }
    }
    return true;
}

void func(int num, int col, int row){
    if(checker(num, col, row)){
        cnt[arr[col][row] + 1]++;
        return;
    }
    num /= 3;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            func(num, col + num * i, row + num  * j);
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> arr[i][j];
        }
    }
    func(n, 0, 0);
    for(int num: cnt) cout << num << '\n';
    
    return 0;
}