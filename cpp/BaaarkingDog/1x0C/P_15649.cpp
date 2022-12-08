/*
문제 : 15649번 N과 M (1)
등급 :  실버 3
링크 : https://www.acmicpc.net/problem/15649
*/
#include <iostream>

using namespace std;

int arr[10];
bool isUsed[10];

int n, m;

void solve(int k){
    if( k == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 1; i <= n; i++){
        if(!isUsed[i]){
            arr[k] = i;
            isUsed[i] = true;
            solve(k + 1);
            isUsed[i] = false;
        }
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    solve(0);
    return 0;
}