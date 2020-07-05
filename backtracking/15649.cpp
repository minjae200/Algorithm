#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 8 + 1;
int N, M;
int sequence[MAX];
bool visited[MAX];

void DFS(int cnt)
{
    if(cnt==M){
        for(int i=0; i<M; i++){
            cout<<sequence[i]<<" ";
        }
        cout<<'\n';
    } 
    for(int i=1; i<=N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        sequence[cnt] = i;
        DFS(cnt+1);
        visited[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N>>M;
    memset(sequence, 0, sizeof(sequence));
    memset(visited, false, sizeof(visited));
    DFS(0);
    return 0;
}