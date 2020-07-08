#include <iostream>
using namespace std;

const int MAX = 1000 + 1;
const int MOD = 10007;
int n;
int cache[MAX];

int solve(int N)
{
    if(N==1) return 1;
    if(N==2) return 3;
    int &ret = cache[N];
    if(ret != -1) return ret;
    ret = (solve(N-1) + 2*solve(N-2)) % MOD;
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);
    cin >> n;
    fill(cache, cache+MAX, -1);
    cout << solve(n) % MOD << '\n';
    return 0;
}