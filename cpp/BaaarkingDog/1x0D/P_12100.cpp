/*
문제 : 12100번 2048 (Easy)
등급 : 골드 2
링크 : https://www.acmicpc.net/problem/12100
*/
#include <iostream>

using namespace std;

int board[22][22];
int cpy[22][22];
int addVis[22][22];
int n, mx = -1;

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
// N -> E -> S -> W

bool OOB(int x, int y) { return x < 0 || x >= n || y < 0 || y >= n; }
void addValue(int nextX, int nextY, int prevX, int prevY) {
    if (addVis[nextX][nextY] || addVis[prevX][prevY]) return;
    addVis[nextX][nextY] = 1;
    cpy[nextX][nextY] *= 2;
    cpy[prevX][prevY] = 0;
}
void moveBlock(int x, int y, int dir) {
    while (1) {
        int prevX = x, prevY = y;
        x += dx[dir];
        y += dy[dir];
        if (OOB(x, y)) return;
        if (cpy[x][y]) {
            if (cpy[x][y] != cpy[prevX][prevY])
                return;
            else {
                addValue(x, y, prevX, prevY);
                continue;
            }
        }
        cpy[x][y] = cpy[prevX][prevY];
        cpy[prevX][prevY] = 0;
        if (addVis[prevX][prevY]) {
            addVis[x][y] = addVis[prevX][prevY];
            addVis[prevX][prevY] = 0;
        }
    }
}
void direct(int dir) {
    // Reset addVis //
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            addVis[i][j] = 0;
        }
    }
    // Move Block ( North or West : dir == 0 || dir == 3)//
    if (dir == 0 || dir == 3) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!cpy[i][j]) continue;
                moveBlock(i, j, dir);
            }
        }
    }
    // Move Block ( East or South : dir == 1 || dir == 2)//
    else {
        for (int i = n - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (!cpy[i][j]) continue;
                moveBlock(i, j, dir);
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    // Input //
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    // Direct //
    for (int cos = 0; cos < (1 << 2 * 5); cos++) {
        // Copy Origin //
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cpy[i][j] = board[i][j];
            }
        }
        // Chose Direct //
        int now = cos;
        for (int i = 0; i < 5; i++) {
            int dir = now % 4;
            now /= 4;
            direct(dir);
        }
        // Chose Max Value //
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cpy[i][j] > mx) mx = cpy[i][j];
            }
        }
    }
    cout << mx << '\n';
    return 0;
}