    #include <iostream>
    #include <queue>
    #include <limits>
    #include <cstring>
    #include <algorithm>
    using namespace std;

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    int N, M, result = -1;
    const int MAX = 8 + 1;
    int map[MAX][MAX];
    bool visited[MAX][MAX];

    void spreadVirus(void)
    {
        queue<pair<int,int>> virus;
        fill(&visited[0][0], &visited[0][0]+sizeof(visited), false);
        // memset(visited, false, sizeof(visited));
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(map[i][j] == 2) {
                    virus.push(make_pair(i,j));
                    visited[i][j] = true;
                }
            }
        }
        while(!virus.empty()) {
            int cur_y = virus.front().first;
            int cur_x = virus.front().second;
            virus.pop();

            for(int i=0; i<4; i++) {
                int next_y = cur_y + dy[i];
                int next_x = cur_x + dx[i];
                if(next_y < 1 || next_x < 1 || next_y > N || next_x > M) continue;
                if(visited[next_y][next_x]) continue;
                if (map[next_y][next_x] == 0) {
                    virus.push(make_pair(next_y, next_x));
                    map[next_y][next_x] = 2;
                    visited[next_y][next_x] = true;
                }
            }
        }
    }

    void makeWall(int cnt) 
    {
        if(cnt==3){
            
            int temp[MAX][MAX];
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=M; j++) {
                    temp[i][j] = map[i][j];
                }
            }
            spreadVirus();
            int safe = 0;
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=M; j++) {
                    if(map[i][j] == 0) safe++;
                }
            }
            result = max(result, safe);
            for(int i=1; i<=N; i++) {
                for(int j=1; j<=M; j++) {
                    map[i][j] = temp[i][j];
                }
            }
            return;
        }
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                if(map[i][j] == 0) {
                    map[i][j] = 1;
                    makeWall(cnt+1);
                    map[i][j] = 0;
                }
            }
        }
    }

    int main(void)
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        freopen("input.txt", "r", stdin);

        cin >> N >> M;
        for( int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                cin >> map[i][j];
            }
        }
        
        makeWall(0);

        cout << result << '\n';
        return 0;
    }