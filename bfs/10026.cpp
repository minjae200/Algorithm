#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100 + 1;
int N;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
bool visited[MAX][MAX];
string v[2][MAX];

void BFS(int idx, int y, int x)
{
    queue<pair<int,int>> q;
    q.push({y, x});
    visited[y][x] = true;
    char color = v[idx][y][x];

    while(!q.empty()) {
        int cur_y = q.front().first;
        int cur_x = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int next_y = cur_y + dy[i];
            int next_x = cur_x + dx[i];
            if(0> next_y || 0 > next_x || next_y >= N || next_x >= N) continue;
            if(visited[next_y][next_x]) continue;
            if(v[idx][next_y][next_x] != color) continue;
            q.push(make_pair(next_y, next_x));
            visited[next_y][next_x] = true;
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);

    cin >> N;
    for(int i=0; i<N; i++) {
        cin >> v[0][i];
        string temp = "";
        for(int j=0; j<v[0][i].size(); j++) {
            char color = v[0][i][j];
            temp += (v[0][i][j] == 'G' ? 'R' : v[0][i][j]);
        }
        v[1][i] = temp;
    }

    vector<int> result;
    for(int i=0; i<2; i++) {
        memset(visited, false, sizeof(visited));
        int ans = 0;
        for(int a=0; a<N; a++) {
            for(int b=0; b<N; b++) {
                if(visited[a][b]) continue;
                BFS(i,a,b);
                ans++;
            }
        }
        result.push_back(ans);
    }

    for(int i=0; i<result.size(); i++) {
        cout << result[i] << " ";
    }
    return 0;
}