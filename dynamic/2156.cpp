#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10000 + 1;
int N;
int grape[MAX], cache[MAX];

int solve(int n)
{
    if(n <= 0) return 0;
    int &ret = cache[n];
    if(ret != -1) return ret;
    ret = max(grape[n-1] + solve(n-3), solve(n-2)) + grape[n];
    ret = max(ret, solve(n-1));
    return ret;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>grape[i];
    }
    memset(cache, -1, sizeof(cache));
    cout<<solve(N)<<'\n';
    return 0;
}