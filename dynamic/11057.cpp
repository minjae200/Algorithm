#include <iostream>
using namespace std;

const int MAX = 1000 + 1;
const int MOD = 10007;
int cache[MAX][10];
int N;

int solve(int n)
{
    for (int i=0; i<10; i++) {
        cache[1][i] = 1;
    }

    for (int i=2; i<=n; i++) {
        for (int j=0; j<10; j++) {
            for(int k=j; k<10; k++) {
                cache[i][j] = (cache[i][j] + cache[i-1][k]) % MOD;
            }
        }
    }
    int ans = 0;
    for (int i=0; i<10; i++) {
        ans = (ans + cache[n][i]) % MOD;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    cout << solve(N) << '\n';
    return 0;
}