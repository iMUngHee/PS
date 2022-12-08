/*
문제 : 2493번 탑
등급 : 골드 5
링크 : https://www.acmicpc.net/problem/2493
*/
#include <iostream>
#include <stack>
#define MAX_HEIGHT 100000001

using namespace std;

stack<pair<int,int>> t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    int pos = 0;
    cin >> n;
    t.push({MAX_HEIGHT, 0});
    for(int i = 1; i <= n; i++){
        int h;
        cin >> h;
        while(t.top().first < h) t.pop();
        cout << t.top().second << ' ';
        t.push({h, i});
    }
    cout << '\n';
    return 0;
}

/* 
    N개의 높이가 다른 탑
    수평 직선의 왼쪽부터 오른쪽 방향으로 세워져 있음
    레이저 신호는 왼쪽 방향으로 발사
    레이저 시호는 가장 먼저 만나는 단 하나의 탑에서만 수신 가능
    EX)
        6 | 9 | 5 | 7 | 4
        0 | 0 | 2 | 2 | 4
    
    입력:
        int n => 탑의 수 ( 1 <= n <= 500,000)
        int h => 탑의 높이 ( 1<= h <= 100,000,000)
    출력: 
        int idx[] => 탑들에서 발사한 레이저 신호를 수신한 탑들의 번호
            존재하지 않으면 0을 출력
    
    EX)
        6 | 9 | 5 | 7 | 20
        0 | 0 | 2 | 2 | 0
    EX)
        9 | 6 | 20 | 7 | 21
        0 | 1 | 0 | 3 | 0
    int pos => 현재 idx
    int cnt => 후진한만큼 카운트, 끝나면 pos에 다시 더 함
    
    앞으로 전진하면서 현재 높이보다 작으면 담을 필요 없음

    1. 비어있으면 0 출력
    2. 지보다 작거나 같으면 top값 출력
    3. 높은 값 스택에 push
    4. 작으면 버림

    => 메모리 초과
    => <pair> 이용해야 함 >> O(N)
    0. pair {height, index}
    1. 더미 push
    2*. top이 입력된 높이보다 작으면 pop
    3. top이 입력된 높이보다 크면 출력 후 push
*/
