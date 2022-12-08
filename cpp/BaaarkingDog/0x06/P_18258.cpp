/*
문제 : 18258번 큐 2
등급 : 실버 4
링크 : https://www.acmicpc.net/problem/18258
*/
#include <iostream>

const int MX = 2000001;
int dat[MX];
int tail, head;

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    while(n--){
        string order;
        cin >> order;
        if(order == "push"){
            int x;
            cin >> x;
            dat[tail++] = x;
        } else if(order == "pop"){
            if(tail == head){
                cout << -1 << '\n';
                continue;
            }
            cout << dat[head++] << '\n';
        } else if(order == "size") {
            cout << tail - head << '\n';
        } else if (order == "empty") {
            if(head == tail) cout << 1 << '\n';
            else cout << 0 << '\n';
        } else if (order == "front") {
            if(tail == head){
                cout << -1 << '\n';
                continue;
            }
            cout << dat[head] << '\n';
        } else if (order == "back") {
            if(tail == head){
                cout << -1 << '\n';
                continue;
            }
            cout << dat[tail - 1] << '\n';
        }
    }
    return 0;
}

/*
    push X: 정수 X를 큐에 넣는 연산이다.
    pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    size: 큐에 들어있는 정수의 개수를 출력한다.
    empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
    front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
    back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/
