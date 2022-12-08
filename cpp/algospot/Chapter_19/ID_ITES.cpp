/*
? 문제 : 외계 신호 분석
! 등급 : 중
* 링크 : https://www.algospot.com/judge/problem/read/ITES
*/
#include <iostream>
#include <queue>
using namespace std;

struct RNG {
    unsigned seed;
    RNG() : seed(1983) {}
    unsigned next() {
        unsigned ret = seed;
        seed = ((seed * 214013u) + 2531011u);
        return ret % 10000 + 1;
    }
};

int countRanges(int k, int n) {
    RNG rng;
    queue<int> range;
    int ret = 0, rangeSum = 0;
    for (int i = 0; i < n; i++) {
        // TODO: 구간에 숫자를 추가
        int newSignal = rng.next();
        rangeSum += newSignal;
        range.push(newSignal);

        // TODO: 구간의 합이 k를 초과하는 동안 구간에서 숫자를 뺌
        while (rangeSum > k) {
            rangeSum -= range.front();
            range.pop();
        }

        if (rangeSum == k) ret++;
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tc = 0;
    cin >> tc;
    while (tc--) {
        int n = 0, k = 0;
        cin >> k >> n;

        cout << countRanges(k, n) << '\n';
    }

    return 0;
}

/*
* MEMO *


*/
