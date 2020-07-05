#include <iostream>
#include <limits>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 20 + 1;
int N, res = numeric_limits<int>::max();
int status[MAX][MAX];
bool visited[MAX];

void DFS(int cur, int cnt)
{
    if(cnt==N/2){
        int start = 0, link = 0;
        for(int i=1; i<=N; i++){
            for(int j=1; j<=N; j++){
                if(visited[i] && visited[j]) start += status[i][j];
                if(!visited[i] && !visited[j]) link += status[i][j];
            }
        }
        res = min(res, abs(start-link));
        return;
    }
    for(int i=cur; i<=N; i++){
        visited[i] = true;
        DFS(i+1, cnt+1);
        visited[i] = false;
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            cin>>status[i][j];
        }
    }
    memset(visited, false, sizeof(visited));
    DFS(1, 0);
    cout<<res<<'\n';
    return 0;
}