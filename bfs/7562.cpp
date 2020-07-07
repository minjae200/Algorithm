#include <iostream>
#include <queue>
using namespace std;

const int MAX = 300 + 1;
int dy[8]={-1,-2,-2,-1,1,2,1,2};
int dx[8]={-2,-1,1,2,-2,-1,2,1};
int l, start_y, start_x, end_y, end_x;
bool visited[MAX][MAX];

int BFS(int y, int x)
{
    queue<pair<int,int>> q;
    q.push(make_pair(y, x));
    visited[y][x] = true;

    int ans = 0;
    bool find = false;
    while(!q.empty()) {
        int q_size = q.size();
        while(q_size--){
            int cur_y = q.front().first;
            int cur_x = q.front().second;
            q.pop();
            if(cur_y == end_y && cur_x == end_x) {
                find = true;
                break;
            }
            for(int i=0; i<8; i++) {
                int next_y = cur_y + dy[i];
                int next_x = cur_x + dx[i];
                if(next_y < 0 || next_x < 0 || next_y >= l || next_x >= l) continue;
                if(visited[next_y][next_x]) continue;
                q.push(make_pair(next_y, next_x));
                visited[next_y][next_x] = true;
            }
        }
        if(find) break;
        ans++;
    }
    return ans;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int TC; cin >> TC;
    while(TC--) {
        cin >> l;
        cin >> start_y >> start_x;
        cin >> end_y >> end_x;
        fill(&visited[0][0], &visited[0][0]+sizeof(visited), false);
        cout << BFS(start_y, start_x) << '\n';
    }
    return 0;
}