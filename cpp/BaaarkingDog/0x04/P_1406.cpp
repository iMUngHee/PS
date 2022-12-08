/*
문제 : 1406번 에디터
등급 : 실버 3
링크 : https://www.acmicpc.net/problem/1406
*/
#include <iostream>
#include <list>

using namespace std;

int num[9];

list<char> editor;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    cin >> str;
    for(char c : str) {
        editor.push_back(c);
    }
    int M;
    cin >> M;
    list<char>::iterator it = editor.end();
    for(int i = 0; i < M; i++){
        char order;
        cin >> order;
        if(order == 'L'){
            if(it != editor.begin()) it--;
        } else if (order == 'D') {
            if(it != editor.end()) it++;
        } else if (order == 'B') {
            if(it != editor.begin()){
                it--;
                it = editor.erase(it);
            }
        } else if (order == 'P') {
            char input;
            cin >> input;
            editor.insert(it, input);
        }
    }
    for(auto a : editor) cout << a;
    cout << '\n';
    return 0;
}

/*
    한 줄로 된 간단한 에디터
    영어 소문자만 기록
    최대 600,000 글자
    커서 - 문장의 맨 앞 / 문장의 맨 뒤/ 문장 중간 임의의 곳 => 위치 가능
        시작 시 맨 뒤에 위치
    명렁어 {
        L >> 커서를 왼쪽으로 한 칸 옮김 ( 문장 맨 앞이면 무시 ) 
        D >> 커서를 오른쪽으로 한 칸 옮김 ( 문장 맨 뒤면 무시 )
        B >> 커서 왼쪽에 있는 문자를 삭제 ( 커서가 맨 앞이면 무시 ),
            삭제로 인해 커서는 한칸 왼쪽으로 이동한 것처럼 나타 나지만, 실제로 커서의 오른쪽에 있던 문자는 그대로
        P $ >> $라는 문자를 커서 왼쪽에 추가
    }
    입력 :
        초기에 편집기에 입력되어 있는 문자열
        문자열 길이 N ( N < 100,000)
        입력할 명령어의 개수 M ( 1 <= M <= 500,000)
        M개의 명령어
*/