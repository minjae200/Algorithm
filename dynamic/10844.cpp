#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int MOD = 1000000000;
const int MAX = 100 + 1;
int N;
ll cache[MAX][10];

ll solve(int n, int m)
{
    if(m < 0 || m > 9) return 0;
    if(n==1) return 1;
    ll &ret = cache[n][m];
    if(ret != -1) return ret;
    ret = solve(n-1, m-1) % MOD + solve(n-1, m+1) % MOD;
    return ret % MOD;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(cache, -1, sizeof(cache));
    // freopen("input.txt", "r", stdin);
    cin>>N;
    ll res = 0;
    for(int i=1; i<=9; i++){
        res = (res + solve(N, i)) % MOD;
    }
    cout<<res % MOD<<'\n';
    return 0;
}