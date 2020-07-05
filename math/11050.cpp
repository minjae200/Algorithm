#include <iostream>
using namespace std;

const int MAX = 100;

int binomial_coefficient(int n, int k)
{
    int C[MAX][MAX];
    int m;
    for(int i=0; i<=n; i++){
        m = (i<k) ? i : k;
        for(int j=0; j<=m; j++){
            if(j==0 || j==i) C[i][j] = 1;
            else C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    return C[n][k];
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int n, k;
    cin>>n>>k;
    cout<<binomial_coefficient(n,k)<<'\n';
    return 0;
}