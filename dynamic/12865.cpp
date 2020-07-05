#include <iostream>
using namespace std;

const int MAX = 100 + 1;
int w[MAX], v[MAX];
int cache[MAX][100000 + 1];
int n, k;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>n>>k;
    for(int i=1; i<=n; i++){
        cin>>w[i]>>v[i];
    }
    for(int i=1; i<=n; i++){
        for(int j=0; j<=k; j++){
            cache[i][j] = cache[i-1][j];
            if(j-w[i] >= 0){
                cache[i][j] = max(cache[i][j], cache[i-1][j-w[i]]+v[i]);
            }
        }
    }
    cout<<cache[n][k]<<'\n';
    return 0;
}