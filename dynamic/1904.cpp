#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int MOD = 15746;
const int MAX = 1000000 + 1;
int N;
ll cache[MAX];

ll solve(int n)
{
    if(n <= 1) return 1;
    ll &ret = cache[n];
    if(ret != -1) return ret;
    ret = solve(n-1)%MOD + solve(n-2)%MOD;
    return ret%MOD;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N;
    memset(cache, -1, sizeof(cache));
    cout<<solve(N)<<'\n';
    return 0;
}