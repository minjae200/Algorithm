#include <iostream>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX = 100 + 1;
const int ValueMAX= 10000 + 1;
const int INF = numeric_limits<int>::max();
int n, k;
int coin[MAX], cache[ValueMAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> n >> k;

    for (int i=1; i<=n; i++) {
        cin >> coin[i];

    }
    fill(cache, cache+ValueMAX, INF);
    cache[0] = 0;
    for (int i=1; i<=k; i++) {
        for (int j=1; j<=n; j++) {
            if (i-coin[j] >= 0 && cache[i-coin[j]] != INF) {
                cache[i] = min(cache[i], cache[i-coin[j]]+1);
            }
        }
    }
    cout << ((cache[k] == INF) ? -1 : cache[k]) << '\n';
    return 0;
}