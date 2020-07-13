#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 100 + 1;
const int valueMax = 100000 + 1;
int n, k;
int coins[MAX];
int cache[valueMax];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> n >> k;
    for (int i=1; i<=n; i++) {
        cin >> coins[i];
    }

    cache[0] = 1;
    for (int i=1; i<=n; i++) {
        for(int j=1; j<=k; j++){
            if(j >= coins[i]) {
                cache[j] += cache[j-coins[i]];
            }
        }
    }
    cout << cache[k] << '\n';
    return 0;
}