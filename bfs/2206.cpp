#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000 + 1;
int N, M;
string board[MAX];
bool visited[MAX][MAX][2];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

struct State {
    int y, x;
    bool broken;
};

int BFS(int y, int x)
{
    memset(visited, false, sizeof(visited));
    queue<State> q;
    q.push({y, x, false});
    visited[y][x][false] = true;
    int ans = 0;
    bool find = false;
    while (!q.empty()) {
        int q_size = q.size();
        while (q_size--){
            State cur = q.front();
            q.pop();
            
            if (cur.y == N-1 && cur.x == M-1) {
                find = true;
                break;
            }

            for (int i=0; i<4; i++) {
                State next;
                next.y = cur.y + dy[i];
                next.x = cur.x + dx[i];
                next.broken = cur.broken;

                if (0 > next.y || 0 > next.x || next.y >= N || next.x >= M) continue;
                if (visited[next.y][next.x][next.broken]) continue;
                if (board[next.y][next.x] == '1' && next.broken == false) {
                    q.push({next.y, next.x, !next.broken});
                    visited[next.y][next.x][!next.broken] = true;
                } else if (board[next.y][next.x] == '0') {
                    q.push({next.y, next.x, next.broken});
                    visited[next.y][next.x][next.broken] = true;
                }
            }
        }
        ans++;
        if(find) break;
    }
    if(!find) return -1;
    else return ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i=0; i<N; i++) {
        cin >> board[i];
    }

    cout << BFS(0, 0) << '\n';
    return 0;
}