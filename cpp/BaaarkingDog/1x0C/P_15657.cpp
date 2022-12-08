/*
문제 : 15657번 N과 M (8)
등급 :  실버 3
링크 : https://www.acmicpc.net/problem/15657
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int arr[10];
bool isUsed[10002];

int n, m;

void solve(int k){
    if( k == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        isUsed[arr[0]] = 1;
        return;
    }
    for(int i = 0; i < n; i++){
        if(isUsed[v[i]]) continue;
        if(k && v[i] < arr[k - 1]) continue;
        arr[k] = v[i];
        solve(k + 1);
    }
    return;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin(), v.end());
    solve(0);
    return 0;
}