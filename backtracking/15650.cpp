#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 8 + 1;
int N, M;
int sequence[MAX];
bool visited[MAX];

void DFS(int cnt, int cur)
{
    if(cnt==M){
        for(int i=0; i<M; i++){
            cout<<sequence[i]<<" ";
        }
        cout<<'\n';
        return;
    } 
    for(int i=cur; i<=N; i++){
        if(visited[i]) continue;
        visited[i] = true;
        sequence[cnt] = i;
        DFS(cnt+1, i+1);
        visited[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N>>M;
    memset(visited, false, sizeof(visited));
    DFS(0, 1);
    return 0;
}