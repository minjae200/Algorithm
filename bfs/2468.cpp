#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;
int map[MAX][MAX];
bool visited[MAX][MAX];
int N, result = -1;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void BFS(int y, int x, int height)
{
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    visited[y][x] = true;

    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if(1 > next_y || 1 > next_x || N < next_y || N < next_x) continue;
            if(visited[next_y][next_x]) continue;
            if(map[next_y][next_x] > height) {
                visited[next_y][next_x] = true;
                q.push(make_pair(next_y, next_x));
            }
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);

    cin >> N;
    int height = 0;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> map[i][j];
            if(height < map[i][j]) height = map[i][j];
        }
    }

    for(int i=0; i<=height; i++) {
        memset(visited, false, sizeof(visited));
        int ans = 0;
        for(int y=1; y<=N; y++) {
            for(int x=1; x<=N; x++) {
                if(map[y][x] > i && !visited[y][x]) {
                    ans++;
                    BFS(y,x,i);
                }
            }
        }
        result = max(result, ans);
    }
    cout << result << '\n';
    return 0;
}