#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int A[MAX], cache[MAX];
int N, res = -1;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i=1; i<=N; i++) {
        cin >> A[i];
    }

    for (int i=1; i<=N; i++) {
        cache[i] = A[i];
        for (int j=1; j<i; j++) {
            if (A[i] > A[j] && cache[i] < cache[j] + A[i]) {
                cache[i] = cache[j] + A[i];
            } 
        }
        res = max(res, cache[i]);
    }

    cout << res << '\n';
    return 0;
}