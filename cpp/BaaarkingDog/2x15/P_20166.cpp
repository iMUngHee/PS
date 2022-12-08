/*
? 문제 : 20166번 문자열 지옥에 빠진 호석
! 등급 : 골드 4
* 링크 : https://www.acmicpc.net/problem/20166
*/
#include <iostream>
#include <unordered_map>
#include <vector>
#define KEY first
#define VALUE second
using namespace std;

string board[12];
unordered_map<string, int> selected_count;
vector<string> order;
int n, m, k;

void move_board(int x, int y, string cur_str);
int x_out_of_board(int x);
int y_out_of_board(int y);
void check_selected(string str);

int dx[8] = {0, 1, 0, -1, 1, -1, 1, -1};
int dy[8] = {1, 0, -1, 0, 1, -1, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> board[i];
    while (k--) {
        string word;
        cin >> word;
        selected_count.insert({word, 0});
        order.push_back(word);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            string s(1, board[i][j]);
            move_board(i, j, s);
        }
    }

    for (auto word : order) {
        cout << selected_count.find(word)->VALUE << '\n';
    }
    return 0;
}

void move_board(int x, int y, string cur_str) {
    check_selected(cur_str);
    if (cur_str.size() == 5) return;
    for (int dir = 0; dir < 8; dir++) {
        int nx = x_out_of_board(x + dx[dir]);
        int ny = y_out_of_board(y + dy[dir]);

        string next_str = cur_str + board[nx][ny];
        move_board(nx, ny, next_str);
    }
}

void check_selected(string str) {
    if (selected_count.count(str)) {
        selected_count.find(str)->VALUE++;
    }
}

int x_out_of_board(int x) {
    if (x >= n) {
        return n - x;
    }
    if (x < 0) {
        return n + x;
    }

    return x;
}
int y_out_of_board(int y) {
    if (y >= m) {
        return m - y;
    }
    if (y < 0) {
        return m + y;
    }

    return y;
}

/*
* MEMO *


*/
