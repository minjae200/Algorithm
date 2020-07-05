#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

const int MAX = 100 + 1;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

int BFS(int n, int m)
{
    queue<pair<int,int>> q;
    q.push(make_pair(1,1));
    visited[1][1] = true;
    int ans = 1;

    while(!q.empty()) {
        int q_size = q.size();
        while(q_size--) {
            pair<int, int> data = q.front();
            if(data.first == n && data.second == m) return ans;
            q.pop();
            for(int i = 0; i < 4; i++) {
                pair<int, int> next = make_pair(data.first + dx[i], data.second + dy[i]);
                if(next.first < 1 || next.first > n || next.second < 1 || next.second > m) continue;
                if(visited[next.first][next.second]) continue;
                if(!map[next.first][next.second]) continue;
                visited[next.first][next.second] = true;
                q.push(make_pair(next.first, next.second));
            }
        }
        ans++;
    }
    return -1;
}

int main(void)
{
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= M; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    memset(visited, false, sizeof(visited));
    printf("%d\n", BFS(N, M));
    return 0;
}