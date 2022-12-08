/*
? 문제 : 록  페스티벌
! 등급 : 하
* 링크 : https://www.algospot.com/judge/problem/read/FESTIVAL
*/
#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
    cout << fixed;
    cout.precision(11);
    int tc;
    cin >> tc;
    while (tc--) {
        int n, l;
        cin >> n >> l;
        int *arr = new int[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        double min = 101;
        for (int k = l; k <= n; k++) {
            for (int i = 0; i < n - k + 1; i++) {
                double sum = 0;
                for (int j = 0; j < k; j++) {
                    sum += arr[i + j];
                }
                if (min > (sum / k)) min = (double)(sum / k);
            }
        }
        cout << min << '\n';
    }
    return 0;
}