#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100 + 1;
int map[MAX][MAX];
bool visited[MAX][MAX];
vector<int> area;
int M, N, K;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};

void BFS(int y, int x)
{
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));
    visited[y][x] = true;

    int ans = 0;
    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();
        ans++;
        for(int i=0; i<4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if(next_y < 0 || next_x < 0 || next_y >= M || next_x >= N) continue;
            if(visited[next_y][next_x]) continue;
            if(map[next_y][next_x] == 1) continue;
            visited[next_y][next_x] =true;
            q.push(make_pair(next_y, next_x));
        }
    }
    area.push_back(ans);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> M >> N >> K;

    for(int k=0; k<K; k++) {
        int left_x, left_y, right_x, right_y;
        cin >> left_x >> left_y >> right_x >> right_y;
        right_x--; right_y--;

        for(int i=left_y; i<=right_y; i++) {
            for(int j=left_x; j<=right_x; j++) {
                map[i][j] = 1;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    int cnt = 0;
    for(int i=0; i<M; i++) {
        for(int j=0; j<N; j++) {
            if(visited[i][j]) continue;
            if(map[i][j] != 0) continue;
            BFS(i,j);
            cnt++;
        }
    }
    sort(area.begin(), area.end());
    cout << cnt << '\n';
    for(int i=0; i<area.size(); i++){
        cout << area[i] << " ";
    }
    return 0;
}