/*
문제 : 15686번 치킨 배달
등급 : 골드 5
링크 : https://www.acmicpc.net/problem/15686
*/
#include <iostream>
#include <vector>
#define X first
#define Y second

using namespace std;

vector<pair<int, int>> ch;
vector<pair<int, int>> selected;
vector<pair<int, int>> house;

int board[52][52];
int isUsed[15];
int n, m, ans = 987654321;
int min(int a, int b) {if(a < b) return a; return b;}
int Cal() {
    int result = 0;
    for (int t = 0; t < house.size(); t++) {
        auto h = house[t];
        int mn = 987654321;
        for (int k = 0; k < selected.size(); k++) {
            auto c = selected[k];
            int dist = abs(c.X - h.X) + abs(c.Y - h.Y);
            mn = min(dist, mn);
        }
        result += mn;
    }
    return result;
}

void solution(int idx) {
    if (selected.size() == m) {
        int d = Cal();
        ans = min(d, ans);
        return;
    }
    for (int i = idx; i < ch.size(); i++) {
        if(isUsed[i]) continue;
        selected.push_back(ch[i]);
        isUsed[i] = 1;
        solution(i);
        isUsed[i] = 0;
        selected.pop_back();
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
            if (board[i][j] == 1) house.push_back({i, j});
            if (board[i][j] == 2) ch.push_back({i, j});
        }
    }
    solution(0);
    cout << ans << '\n';
    return 0;
}
