/*
문제 : 9466번 텀 프로젝트
등급 : 골드 3
링크 : https://www.acmicpc.net/problem/9466
*/
#include <iostream>

using namespace std;

int board[100002];
int team[100002];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        int n;
        cin >> n;
        fill(team + 1, team + n + 1, 0);
        for(int i = 1; i <= n; i++)
            cin >> board[i];
        for(int i = 1; i <= n; i++){
            if(!team[i]){
                int cur = i;
                while(true){
                    // if(team[cur] == -1) team[cur] = 1;
                    // if(team[board[cur]] == 1) break;
                    // if(team[cur] == 0) team[cur] = -1;
                    team[cur] = i;
                    cur = board[cur];
                    if(team[cur] == i){
                        while(team[cur] != -1){
                            team[cur] = -1;
                            cur = board[cur];
                        }
                        break;
                    }
                    else if (team[cur] != 0) break;
                }
            }
            // else if(team[board[i]] && !team[i]) team[i] = -1;
        }
        int ans = 0;
        for(int i = 1; i <= n; i++) if(team[i] != -1) ans++;
        cout << ans << '\n';
    }
    return 0;
}

/*
    팀 짜기
    선택으로 순환해야 한 팀
    input:
        tc => test case
        n => 학생 수 1 <= n, m <= 100,000
        학생들 선택
    output:
        ans => 프로젝트 팀에 속하지 못한 학생들의 수
*/
