#include <iostream>
#include <cstring>
#include <algorithm>
#include <limits>
using namespace std;

const int MAX = 500 + 1;
int n;
int triangle[MAX][MAX];
int cache[MAX][MAX];
int res = numeric_limits<int>::min();

int solve(int R, int C)
{
    if(R<1 || C>R) return 0;
    int &ret = cache[R][C];
    if(ret != -1) return ret;
    return ret = max(solve(R-1, C), solve(R-1, C-1)) + triangle[R][C];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>n;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cin>>triangle[i][j];
        }
    }
    memset(cache, -1, sizeof(cache));
    for(int i=1; i<=n; i++){
        res = max(res, solve(n, i));
    }
    cout<<res<<'\n';
    return 0;
}