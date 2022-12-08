/*
문제 : 15652번 N과 M (4)
등급 :  실버 3
링크 : https://www.acmicpc.net/problem/15652
*/
#include <iostream>

using namespace std;

int arr[10];
bool isUsed[10];
bool isUsed2[10];

int n, m;

void solve(int k){
    if( k == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        isUsed[arr[0]] = 1;
        return;
    }
    
    for(int i = 1; i <= n; i++){
        if(!isUsed[i]){
            if(k && arr[k-1] > i) continue;
            arr[k] = i;
            solve(k + 1);
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