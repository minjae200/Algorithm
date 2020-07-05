#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100000 + 1;
int N, M;
bool visited[MAX];
queue<int> q;

int BFS(int start)
{
    int ans = 0;
    q.push(start);
    visited[start] = true;

    bool find = false;
    while(!q.empty()){
        int q_size = q.size();
        while(q_size--){
            int cur = q.front();
            q.pop();
            if (cur == M) {
                find = true;
                break;
            }
            if(cur-1 >= 0 && !visited[cur-1]) {
                q.push(cur-1);
                visited[cur-1] = true;
            }
            if(cur+1 <= MAX && !visited[cur+1]) {
                q.push(cur+1);
                visited[cur+1] = true;
            }

            if(2*cur <= MAX && !visited[2*cur]) {
                q.push(2*cur);
                visited[2*cur] = true;
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
    freopen("input.txt", "r", stdin);

    cin >> N >> M;
    fill(visited, visited+MAX, false);

    cout << BFS(N);
    return 0;
}