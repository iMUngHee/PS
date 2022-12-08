/*
문제 : 16987번 계란으로 계란치기
등급 :  실버 1
링크 : https://www.acmicpc.net/problem/16987
*/
#include <iostream>
#include <vector>
#define S first
#define W second

using namespace std;

vector<pair<int,int>> eggs;
vector<pair<int,int>> tmp;
int n, ans, cnt;

void solve(int cur){
    if(cur == n){
        if(ans < cnt) ans = cnt;
        return;
    }
    if(eggs[cur].S < 1 || cnt == n - 1){
        solve(cur + 1);
        return;
    }
    for(int i = 0; i < n; i++){
        if(i == cur or eggs[i].S < 1) continue;
        eggs[i].S -= eggs[cur].W;
        eggs[cur].S -= eggs[i].W;
        if(eggs[i].S < 1) cnt++;
        if(eggs[cur].S < 1) cnt++;
        solve(cur + 1);
        if(eggs[i].S < 1) cnt--;
        if(eggs[cur].S < 1) cnt--;
        eggs[i].S += eggs[cur].W;
        eggs[cur].S += eggs[i].W;
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 0; i < n; i++){
        int shield, weight;
        cin >> shield >> weight;
        eggs.push_back({shield, weight});
    }
    solve(0);
    cout << ans << '\n';
    return 0;
}

/** 
 *  계란 깨기
 *  계란 : 내구도 / 무게
 *  내구도 => 한 턴에 상대 무게만큼 깎임
 *  계란 깨기 규칙)
 *  1. 가장 왼쪽의 계란을 든다
 *  2. 손에 들고 있는 계란으로 다른 계란중 하나를 친다.
 *      2-1. 손에 든 계란이 깨졌거나 깨지지 않은 다른 계란이 없으면 치지 않고 넘어감
 *      2-2. 이후 손에 든 계란을 원래 자리에 내려놓고 3번 과정 진행
 *  3. 가장 최근에 든 계란의 한 칸 오른쪽 계란을 손에 들고 2번 과정 다시 진행
 *      3-1. 단, 가장 최근에 든 계란이 가장 오른쪽에 위치한 계란일 경우 계란을 치는 과정을 종료
 *  
 *  Input:
 *      n => 계란의 수
 *      S, W => 각 계란의 내구도와 무게
 *  Output:
 *      ans => 깰 수 있는 계란의 최대 개수
*/