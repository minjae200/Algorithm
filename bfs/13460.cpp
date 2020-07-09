#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 10 + 1;
int N, M;
bool visited[MAX][MAX][MAX][MAX];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
string board[MAX];


struct Ball
{
    int y, x;
    bool operator==(Ball ball) {
        if (y == ball.y && x == ball.x) return true;
        else return false;
    }
    bool operator!=(Ball ball) {
        if (y != ball.y || x != ball.x) return true;
        else return false;
    }
};

Ball red, blue, hole;

void Move(Ball &ball, int dir)
{
    while(1) {
        ball.y += dy[dir];
        ball.x += dx[dir];
        if(board[ball.y][ball.x] == '#') {
            ball.y -= dy[dir];
            ball.x -= dx[dir];
            break;
        } else if(board[ball.y][ball.x] == 'O') break;
    }
}

int BFS()
{
    queue<pair<Ball, Ball>> q;
    q.push(make_pair(red, blue));
    visited[red.y][red.x][blue.y][blue.x] = true;
    int ans = 0;

    bool find = false;
    while(!q.empty()) {
        int q_size = q.size();
        while(q_size--) {
            Ball cur_red = q.front().first;
            Ball cur_blue = q.front().second;
            q.pop();
            
            if(cur_red == hole && cur_blue != hole) {
                find = true;
                break;
            }
            for(int i=0; i<4; i++) {
                Ball next_red = cur_red;
                Ball next_blue = cur_blue;
                Move(next_red, i);
                Move(next_blue, i);
                if(next_blue == hole) continue;
                if(next_red == next_blue) {
                    switch(i){
                    case 0:
                        cur_red.y < cur_blue.y ? next_blue.y++ : next_red.y++;
                        break;
                    case 1:
                        cur_red.y < cur_blue.y ? next_red.y-- : next_blue.y--;
                        break;
                    case 2:
                        cur_red.x < cur_blue.x ? next_blue.x++ : next_red.x++;
                        break;
                    case 3:
                        cur_red.x < cur_blue.x ? next_red.x-- : next_blue.x--;
                        break;
                    }
                }
                if(visited[next_red.y][next_red.x][next_blue.y][next_blue.x]) continue;
                visited[next_red.y][next_red.x][next_blue.y][next_blue.x] = true;
                q.push(make_pair(next_red, next_blue));
            }
        }
        if(find) break;
        ans++;
        if(ans > 10) {
            ans = -1;
            break;
        }
    }
    if (!find) ans = -1;
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for(int i=0; i<N; i++) {
        cin >> board[i];
        for(int j=0; j<board[i].size(); j++) {
            if(board[i][j] == 'B') {
                blue.y = i; blue.x = j;
            } else if(board[i][j] == 'R') {
                red.y = i; red.x = j;
            } else if(board[i][j] == 'O') {
                hole.y = i; hole.x = j;
            }
        }
    }
    memset(visited, false, sizeof(visited));
    cout << BFS() << '\n';
    return 0;
}