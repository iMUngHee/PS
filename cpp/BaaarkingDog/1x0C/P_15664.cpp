/*
문제 : 15664번 N과 M (10)
등급 :  실버 2
링크 : https://www.acmicpc.net/problem/15664
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> v;

int arr[10];
int isUsed[10];

int n, m;

void solve(int k){
    if( k == m) {
        for(int i = 0; i < m; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int cr = 0;
    if(k != 0) cr = arr[k - 1];
    int cmp = 0;
    for(int i = 0; i < n; i++){
        if(v[i] < cr) continue;
        if(!isUsed[i] && cmp != v[i]){
            isUsed[i] = 1;
            arr[k] = v[i];
            cmp = arr[k];
            solve(k + 1);
            isUsed[i] = 0;
        }
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