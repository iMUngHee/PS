/*
문제 : 2630번 색종이 만들기
등급 :  실버 3
링크 : https://www.acmicpc.net/problem/2630
*/
#include <iostream>

using namespace std;

int n;
int arr[130][130];
int cnt[2];

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
        cnt[arr[col][row]]++;
        return;
    }
    num /= 2;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
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