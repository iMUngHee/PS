/*
문제 : 12094번 2048 (Hard)
등급 : 플레티넘 4
링크 : https://www.acmicpc.net/problem/12094
*/
#include <algorithm>
#include <iostream>

using namespace std;

int board[20][20];
int n, mx = -1;

void rotate() {
    int tmp[22][22];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) tmp[i][j] = board[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) board[i][j] = tmp[n - 1 - j][i];
}
void moveBlock() {
    for (int i = 0; i < n; i++) {
        int tmp[22] = {0, };
        bool join[20] = {0 ,};
        int idx = 0;
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 0) continue;
            if (tmp[idx] == 0)
                tmp[idx] = board[i][j];
            else if (tmp[idx] && join[idx])
                tmp[++idx] = board[i][j];
            else if (tmp[idx] == board[i][j]){
                tmp[idx] *= 2;
                join[idx++] = true;
            }
            else
                tmp[++idx] = board[i][j];
        }
        for (int j = 0; j < n; j++) board[i][j] = tmp[j];
    }
};

void reset(int tmp[][20]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) board[i][j] = tmp[i][j];
}

bool isChanged(int arr[][20], int arr2[][20]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (arr[i][j] != arr2[i][j]) return true;
    return false;
}

void solution(int depth) {
    int tmp[20][20];
    int curMx = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            tmp[i][j] = board[i][j];
            curMx = max(curMx, board[i][j]);
        }
    }
    mx = max(mx, curMx);
    if (depth == 10) return;
    if (curMx * 1 << (10 - depth) <= mx) return;

    moveBlock();
    if (isChanged(tmp, board)) {
        solution(depth + 1);
        reset(tmp);
    }

    rotate();
    rotate();
    moveBlock();
    rotate();
    rotate();
    if (isChanged(tmp, board)) {
        solution(depth + 1);
        reset(tmp);
    }

    rotate();
    rotate();
    rotate();
    moveBlock();
    rotate();
    if (isChanged(tmp, board)) {
        solution(depth + 1);
        reset(tmp);
    }

    rotate();
    moveBlock();
    rotate();
    rotate();
    rotate();
    if (isChanged(tmp, board)) {
        solution(depth + 1);
        reset(tmp);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> board[i][j];
        }
    }
    solution(0);
    cout << mx;
    return 0;
}