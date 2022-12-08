/*
? 문제 : 1351번 무한 수열
! 등급 : 골드 5
* 링크 : https://www.acmicpc.net/problem/1351
*/
#include <iostream>
#include <unordered_map>
using namespace std;
long long n, p, q;
unordered_map<long long, long long> M;
long long solution(long long i) {
    if (i == 0) return 1;
    if (M.count(i)) return M.find(i)->second;
    long long next = solution(i / p) + solution(i / q);
    M.insert({i, next});
    return next;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> p >> q;
    cout << solution(n) << '\n';

    return 0;
}

/*
* MEMO *
⭐️ DivisionByZero -> Overflow

*/
