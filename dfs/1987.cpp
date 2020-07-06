#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX = 20 + 1;
int R, C, result = 1;
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};
bool used[26];
char map[MAX][MAX];

void DFS(int r, int c, int cnt)
{
    used[map[r][c] - 'A'] = true;
    for(int i=0; i<4; i++) {
        int next_r = r + dr[i];
        int next_c = c + dc[i];
        if(0 > next_r || 0 > next_c || next_r >= R || next_c >= C) continue;
        if(used[map[next_r][next_c]-'A']) continue;
        DFS(next_r, next_c, cnt + 1);
    }
    result = max(result, cnt);
    used[map[r][c] - 'A'] = false;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> R >> C;
    for(int i=0; i<R; i++) {
        for(int j=0; j<C; j++) {
            cin >> map[i][j];
        }
    }
    DFS(0, 0, 1);
    cout << result << '\n';
    return 0;
}