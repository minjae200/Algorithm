#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1000 + 1;
int M, N, tomato, cnt;
int map[MAX][MAX];
queue<pair<int,int>> q;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int BFS(void)
{
    int ans = -1;
    while(!q.empty()) {
        int q_size = q.size();
        while(q_size--) {
            int cur_x = q.front().first;
            int cur_y = q.front().second;
            q.pop();

            for(int i=0; i<4; i++) {
                int next_x = cur_x + dx[i];
                int next_y = cur_y + dy[i];
                if (next_x < 0 || next_y < 0 || next_x >= N || next_y >= M) continue;
                if (map[next_x][next_y] == 0 ){
                    map[next_x][next_y] = 1;
                    q.push({next_x, next_y});
                    cnt++;
                }
            }
        }
        ans++;
    }

    if (cnt == tomato) return ans;
    else return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    cin >> M >> N;
    tomato = M * N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<M; j++) {
            cin >> map[i][j];
            if(map[i][j] == 1) {
                q.push({i,j});
                cnt++;
            } else if (map[i][j] == -1) {
                tomato--;
            }
        }
    }

    cout<< BFS() << '\n';
    return 0;
}