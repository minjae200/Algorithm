#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 100000 + 1;
int N;
int cache[2][MAX], sticker[2][MAX];

/* int solve(int row, int n)
{
    if(n <= 0) return 0;
    int &ret = cache[row][n];
    if(ret != -1) return ret;
    ret = max(solve(row, n-1), max(solve(!row, n-1), solve(!row, n-1) + sticker[row][n]));
    return ret;
}
 */

int solve(void)
{
    cache[0][1] = sticker[0][1];
    cache[1][1] = sticker[1][1];

    for(int i=2; i<=N; i++) {
        cache[0][i] = max(sticker[0][i] + cache[1][i-1], cache[0][i-1]);
        cache[1][i] = max(sticker[1][i] + cache[0][i-1], cache[1][i-1]);
    }
    return max(cache[0][N], cache[1][N]);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int TC; cin >> TC;
    while (TC--) {
        cin >> N;
        memset(cache, -1, sizeof(cache));
        for (int i=0; i<2; i++) {
            for (int j=1; j<=N; j++) {
                cin >> sticker[i][j];
            }
        }
        // cout << max( solve(0, N), solve(1,N)) << '\n';
        cout << solve() << '\n';
    }
    return 0;
}       