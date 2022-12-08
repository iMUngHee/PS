/*
문제 : 18808번 감시
등급 : 골드 3 스티커 붙이기
링크 : https://www.acmicpc.net/problem/18808
*/
#include <iostream>

using namespace std;

int board[42][42];
int sticker[12][12];

int n, m, k;
int r, c;
int ans;

void rotate() {
    int tmp[12][12];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            tmp[i][j] = sticker[i][j];
        }
    }

    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            sticker[i][j] = tmp[r - 1 - j][i];
        }
    }
    swap(r, c);
}

bool isPaste(int x, int y) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (board[x + i][y + j] && sticker[i][j]) return false;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (sticker[i][j]) board[x + i][y + j] = 1;
        }
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    while (k--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) cin >> sticker[i][j];
        for (int deg = 0; deg < 4; deg++) {
            bool done = false;
            for (int i = 0; i <= n - r; i++) {
                if (done) break;
                for (int j = 0; j <= m - c; j++) {
                    if (isPaste(i, j)) {
                        done = true;
                        break;
                    }
                }
            }
            if (done) break;
            rotate();
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans += (board[i][j] == 1);
        }
    }
    cout << ans << '\n';
    return 0;
}
