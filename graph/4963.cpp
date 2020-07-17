#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 50 + 1;
int board[MAX][MAX];
bool visited[MAX][MAX];
int w, h;
int dy[8] = {-1, 1, 0, 0, 1, -1, -1, 1};
int dx[8] = {0, 0, -1, 1, 1, 1, -1, -1};

void BFS(int y, int x)
{
    queue<pair<int,int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = true;

    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for(int i=0; i<8; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];

            if ( 1 > next_y || 1 > next_x || next_y > h || next_x > w) continue;
            if (board[next_y][next_x] != 1) continue;
            if (visited[next_y][next_x]) continue;
            visited[next_y][next_x] = true;
            q.push(make_pair(next_y, next_x));
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    while(1) {
        cin >> w >> h;
        if (w==0 && h==0) break;

        for (int i=1; i<=h; i++) {
            for (int j=1; j<=w; j++) {
                cin >> board[i][j];
            }
        }
        memset(visited, false, sizeof(visited));
        int ans = 0;
        for (int i=1; i<=h; i++) {
            for (int j=1; j<=w; j++) {
                if (visited[i][j]) continue;
                if (board[i][j] != 1) continue;
                BFS(i, j);
                ans++;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}