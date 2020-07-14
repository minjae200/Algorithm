#include <iostream>
#include <cstring>
#include <limits>
#include <cmath>
using namespace std;

const int MAX = 100000 + 1;
const int INF = numeric_limits<int>::max();
int cache[MAX];
int N;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin >> N;

    fill(cache, cache+MAX, INF);
    cache[0] = 0;
    cache[1] = 1;
    for (int i=2; i<=N; i++) {
        int sq = sqrt(i);
        for (int j=1; j<=sq; j++) {
            cache[i] = min(cache[i], cache[i-(j*j)] + 1);
        }
    }
    cout << cache[N] << '\n';
    return 0;
}