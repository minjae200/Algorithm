#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
const int MAX = 100 + 1;
int T, N;
ll cache[MAX];

ll solve(int n)
{
    if(n <= 0) return 0;
    if(n <= 3) return 1;
    ll &ret = cache[n];
    if(ret != -1) return ret;
    return ret = solve(n-3) + solve(n-2);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    memset(cache, -1, sizeof(cache));
    cin>>T;
    while(T--){
        cin>>N;
        cout<<solve(N)<<'\n';
    }
    return 0;
}