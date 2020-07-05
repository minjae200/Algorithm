#include <iostream>
using namespace std;

const int MAX = 10 + 1;
int N, K;
int coin[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N>>K;
    for(int i=1; i<=N; i++){
        cin>>coin[i];
    }
    int idx = N;
    int res = 0;
    while(K > 0){
        if(K < coin[idx]){
            idx--;
            continue;
        }
        int cnt = K / coin[idx];
        K -= coin[idx] * cnt;
        res += cnt;
    }
    cout<<res<<'\n';
    return 0;
}