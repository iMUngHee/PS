/*
문제 : 1992번 쿼드트리
등급 :  실버 1
링크 : https://www.acmicpc.net/problem/1992
*/
#include <iostream>

using namespace std;

int n;
string arr[100];

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
        if(arr[col][row] == '1'){
            cout << 1;
            return;
        }
        cout << 0;
        return;
    }
    num /= 2;
    cout << '(';
    func(num, col, row);
    func(num, col, row + num);
    func(num, col + num, row);
    func(num, col + num, row + num);
    cout << ')';
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    func(n, 0, 0);
    cout << '\n';
    return 0;
}