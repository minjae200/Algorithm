#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX = 50 + 1;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int M, N, K;

void BFS(int y, int x) 
{
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    visited[y][x] = true;

    while(!q.empty()){
        int cur_x = q.front().second;
        int cur_y = q.front().first;
        q.pop();

        for(int i=0; i<4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if(next_y < 0 ||  next_x < 0 || next_y >= N || next_x >= M) continue;
            if(visited[next_y][next_x]) continue;
            if(map[next_y][next_x] == 1){
                visited[next_y][next_x] = true;
                q.push({next_y, next_x});
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int TC; cin >> TC;
    while(TC--){
        memset(map, 0, sizeof(map));
        memset(visited, false, sizeof(visited));
        cin >> M >> N >> K;
        for(int i=0; i<K; i++){
            int x, y;
            cin >> x >> y;
            map[y][x] = 1;
        }
        int res = 0;
        for(int i=0; i<N; i++) {
            for(int j=0; j<M; j++) {
                if(visited[i][j]) continue;
                if(map[i][j] == 1){
                    BFS(i,j);
                    res++;
                }
            }
        }
        cout << res  << '\n';
    }
    return 0;
}