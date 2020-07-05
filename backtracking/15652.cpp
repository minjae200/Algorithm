#include <iostream>
using namespace std;

const int MAX = 9;
int N, M;
int seq[MAX];

void DFS(int cnt)
{
    if(cnt==M){
        for(int i=0; i<M; i++){
            cout<<seq[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=1; i<=N; i++){
        if(cnt!=0){
            if(seq[cnt-1] > i) continue;
        }
        seq[cnt] = i;
        DFS(cnt+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N>>M;
    DFS(0);
    return 0;
}