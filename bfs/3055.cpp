#include <iostream>
#include <queue>
#include <cstring>
#include <limits>
using namespace std;

const int MAX = 50 + 1;
const int INF = numeric_limits<int>::max();
int R, C;
bool visited[MAX][MAX];
bool waterVisited[MAX][MAX];
char board[MAX][MAX];

pair<int,int> dest, start, water;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

queue<pair<int,int>> waters;

void waterFall()
{
    int water_size = waters.size();
    while(water_size--) {
        int cur_y = waters.front().first;
        int cur_x = waters.front().second;
        waters.pop();

        for (int i=0; i<4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];

            if (1 > next_y || 1 > next_x || R < next_y || C < next_x) continue;
            if (waterVisited[next_y][next_x]) continue;
            if (board[next_y][next_x] == 'X' || board[next_y][next_x] == 'D') continue;
            waterVisited[next_y][next_x] = true;
            waters.push({next_y, next_x});
            board[next_y][next_x] = '*';
        }
    }

    // for(int i=1;i<=R; i++) {
    //     for(int j=1;j<=C; j++) {
    //         cout << board[i][j];
    //     }
    //     cout<<endl;
    // }
    // cout << endl;
}

int BFS(void) {
    queue<pair<int,int>> q;
    q.push(start);
    visited[start.first][start.second] = true;
    int ans = 0;
    bool find = false;
    while (!q.empty()) {
        int q_size = q.size();
        waterFall();
        while(q_size--) {
            int cur_y = q.front().first;
            int cur_x = q.front().second;
            q.pop();
            if(cur_y == dest.first && cur_x == dest.second) {
                find = true;
                break;
            }
            for (int i=0; i<4; i++) {
                int next_y = cur_y + dy[i];
                int next_x = cur_x + dx[i];
                if (1 > next_y || 1 > next_x || R < next_y || C < next_x) continue;
                if (visited[next_y][next_x]) continue;
                if (board[next_y][next_x] == '*' || board[next_y][next_x] == 'X') continue;
                q.push({next_y, next_x});
                visited[next_y][next_x] = true;
            }
        }
        if(find) break;
        ans++;
    }
    if(find) return ans;
    else return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    cin >> R >> C;
    memset(visited, false, sizeof(visited));
    memset(waterVisited, false, sizeof(waterVisited));
    for (int i=1; i<=R; i++) {
        for (int j=1; j<=C; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'S') {
                start.first = i;
                start.second = j;
            } else if (board[i][j] == 'D') {
                dest.first = i;
                dest.second = j;
            } else if (board[i][j] == '*') {
                waters.push({i,j});
                waterVisited[i][j] = true;
            }
        }
    }
    int result = BFS();
    if(result == -1) cout << "KAKTUS" << '\n';
    else cout << result << '\n';
    return 0;
}