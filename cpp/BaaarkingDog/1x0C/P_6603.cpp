/*
문제 : 6603번 로또
등급 :  실버 2
링크 : https://www.acmicpc.net/problem/6603
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> v;
int arr[10];
int isUsed[50];
int n, num;

void solve(int k){
    if(k == 6){
        for(int i = 0; i < 6; i++)
            cout << arr[i] << ' ';
        cout << '\n';
        return;
    }
    int cr = 0;
    if(k != 0 ) cr = arr[k - 1];
    for(int i = 0; i < n; i++){
        if(cr > v[i]) continue;
        if(!isUsed[v[i]]){
            isUsed[v[i]] = 1;
            arr[k] = v[i];
            solve(k + 1);
            isUsed[v[i]] = 0;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    while(1){
        cin >> n;
        if(!n) break;
        while(!v.empty()) v.pop_back();
        for(int i = 0; i < n; i++){
            cin >> num;
            v.push_back(num);
        }
        solve(0);
        cout << '\n';
    }
    return 0;
}