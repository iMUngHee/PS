/*
문제 : 6198번 옥상 정원 꾸미기
등급 : 골드 5
링크 : https://www.acmicpc.net/problem/6198
*/
#include <iostream>
#include <stack>


using namespace std;

stack<int> building;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    long long ans = 0;
    cin >> n;
    for(int i = 1; i <= n; i++){
        int h;
        cin >> h;
        while(!building.empty() && building.top() <= h){
            building.pop();
        }
        ans += building.size();
        building.push(h);
    }
    cout << ans << '\n';

    return 0;
}

/* 
    N개의 빌딩
    i번째 빌딩의 키 hi
    일렬로 서있고 오른쪽으로만 볼 수 있음
    자신이 위치한 빌딩보다 높거나 같은 빌딩이 있으면 그 다음에 있는 모든 빌딩의 옥상은 보지 못함
    
    EX)
                    = 
        =           = 
        =     -     = 
        =     =     =        -> 관리인이 보는 방향
        =  -  =  =  =   
        =  =  =  =  =  = 
        10 3  7  4  12 2     -> 빌딩의 높이
        [1][2][3][4][5][6]   -> 빌딩의 번호
    입력:
        N => 빌딩의 개수 ( 1 <= N <= 80,000 )
        h => 각 빌딩의 높이 ( 1 <= h <= 1,000,000,000 )
    출력:
        ans => 각 관리인들이 볼 수 있는 빌딩 수의 합
    
    <- 방향으로 볼 때 지한테 몇개가 걸리는가


*/
