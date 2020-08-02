#include <iostream>
using namespace std;

const int MOD = 10007;
const int MAX = 1000 + 1;
int cache[MAX][MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    int N, K;
    cin >> N >> K;

    for (int i=1; i<=N; i++) {
        for (int j=0; j<=N; j++) {
            if(i==j || j==0) {
                cache[i][j] = 1;
                continue;
            }
            cache[i][j] = (cache[i-1][j-1] + cache[i-1][j]) % MOD;
        }
    }
    cout << cache[N][K] << '\n';
    return 0;
}