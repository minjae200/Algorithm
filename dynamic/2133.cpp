#include <iostream>
using namespace std;

const int MAX = 30 + 1;
int N;
int cache[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N;

    cache[0] = 1;
    cache[2] = 3;

    for (int i=4; i<=N; i++) {
        cache[i] = cache[i-2] * 3;
        for (int j=4; j<=i; j+=2) {
            cache[i] += cache[i-j] * 2;
        }
    }

    cout << cache[N] << '\n';
    return 0;
}