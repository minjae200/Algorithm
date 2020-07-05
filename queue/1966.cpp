#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);
    int tc; cin >> tc;

    while (tc--) {
        int N, K;
        cin >> N >> K;
        queue<pair<int,int>> q;
        priority_queue<int> pq;
        for (int i=0; i<N; i++) {
            int prio;
            cin >> prio;
            q.push(make_pair(i, prio));
            pq.push(prio);
        }

        int cnt = 0;
        while(!q.empty()) {
            int index = q.front().first;
            int value = q.front().second;
            q.pop();

            if(pq.top() == value) {
                pq.pop();
                cnt++;
                if ( index == K) {
                    cout << cnt << endl;
                    break;
                }
            }
            else q.push(make_pair(index, value));
        }
    }
    return 0;
}