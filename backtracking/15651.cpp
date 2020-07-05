#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 7 + 1;
int N, M;
int sequence[MAX];

void DFS(int cnt)
{
    if(cnt==M){
        for(int i=0; i<M; i++){
            cout<<sequence[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i = 1; i<=N; i++){
        sequence[cnt] = i;
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