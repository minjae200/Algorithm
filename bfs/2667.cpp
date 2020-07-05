#include <stdio.h>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 25 + 1;
int map[MAX][MAX], N;
bool visited[MAX][MAX];
vector<int> house;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int cnt;

void DFS(pair<int,int> pos)
{
    visited[pos.first][pos.second] = true;
    cnt++;
    for(int i = 0; i < 4; i++) {
        pair<int,int> next = make_pair(pos.first + dx[i], pos.second + dy[i]);
        if(0 > next.first || N <= next.first || 0 > next.second || N <= next.second) continue;
        if(visited[next.first][next.second]) continue;
        if(!map[next.first][next.second]) continue;
        DFS(make_pair(next.first, next.second));
    }
}

int main(void)
{
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    memset(visited, false, sizeof(visited));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] && !visited[i][j]) {
                cnt = 0;
                DFS(make_pair(i,j));
                house.push_back(cnt);
            }
        }
    }
    printf("%d\n", house.size());
    sort(house.begin(), house.end());
    for(int i = 0; i < house.size(); i++) {
        printf("%d\n", house[i]);
    }
    return 0;
}