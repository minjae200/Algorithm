#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 100 + 1;
int box[MAX][MAX][MAX];
int M, N, H, total;
bool visited[MAX][MAX][MAX];

int dz[] = {-1, 1, 0, 0, 0, 0};
int dy[] = {0, 0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 0, -1, 1};


class Tomato
{
public:
    int z, y, x;
    Tomato(int _z, int _y, int _x) : z(_z), y(_y), x(_x) {}
};

queue<Tomato> q;

int BFS(void)
{
    int ans = -1;
    int tomato = q.size();
    while(!q.empty()) {
        int q_size = q.size();
        while(q_size--){
            Tomato cur = q.front();
            q.pop();

            for(int i=0; i<6; i++) {
                int next_z = cur.z + dz[i];
                int next_y = cur.y + dy[i];
                int next_x = cur.x + dx[i];

                if(next_z < 1 || next_y < 1 || next_x < 1 || next_z > H || next_y > N || next_x > M) continue;
                if(box[next_z][next_y][next_x] != 0) continue;
                if(visited[next_z][next_y][next_x]) continue;
                q.push(Tomato(next_z, next_y, next_x));
                visited[next_z][next_y][next_x] = true;
                tomato++;
            }
        }
        ans++;
    }
    if (total == tomato) return ans;
    else return -1;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.txt", "r", stdin);

    cin >> M >> N >> H;

    memset(visited, false, sizeof(visited));
    int non_tomato = 0;
    for(int k=1; k<=H; k++) {
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=M; j++) {
                cin >> box[k][i][j];
                if (box[k][i][j] == 1) {
                    q.push(Tomato(k,i,j));
                    visited[k][i][j] = true;
                } else if(box[k][i][j] == -1) non_tomato++;
            }
        }
    }
    total = H*N*M - non_tomato;
    cout << BFS() << '\n';
    return 0;
}