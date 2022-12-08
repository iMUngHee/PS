/*
문제 : 1158번 요세푸스 문제
등급 : 실버 5
링크 : https://www.acmicpc.net/problem/1158
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> people;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K;
    cin >> N >> K;
    cout << '<';
    for(int i = 1; i <= N; i++){
        people.push_back(i);
    }
    vector<int>::iterator cursor = people.begin();
    while(N--){
        int tmp = K;
        while(tmp--){
            if(tmp == 0) break;
            if(cursor == people.end() - 1) {cursor = people.begin();}
            else {
                cursor++;
            }
        }
        cout << *cursor;
        cursor = people.erase(cursor);
        if(cursor == people.end()) {cursor = people.begin();}
        if(N != 0) cout << ',' << ' ';
    }
    cout << '>' << '\n';
    return 0;
}

/*
    1 ~ N번 까지 N명의 사람이 원을 이루며 앉음
    양의 정수 K(<= N)
    순서대로 K번째 사람을 제거
    N명이 모두 제거될 때 까지 계속
    제거되는 순서를 (N, K) - 요세푸스 순열이라고 함
    
    입력:
        N과 K가 주어짐 ( 1 <= K <= N <= 5,000)
    출력:
        요세푸스 순열을 출력
    
    리스트 뺑뺑이
    한 뺑뻉이에 cnt++ / 현재 뺑뺑이 위치 출력
    cnt == N 일 때 종료
    <1, 2, 3, 4, 5, 6, 7>
*/