#include <iostream>
#include <deque>
using namespace std;

int N, M;
deque<int> dq;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M;
    for (int i=1; i<=N; i++) {
        dq.push_back(i);
    }
    int ans = 0;
    for (int i=0; i<M; i++) {
        int data; cin >> data;

        int idx = 1;
        for (deque<int>::iterator iter = dq.begin(); iter < dq.end(); iter++, idx++) {
            if (*iter == data) break;
        }
        int left = idx - 1;
        int right = dq.size() - idx + 1;
        if (left < right) {
            for (int j=1; j<=left; j++) {
                dq.push_back(dq.front());
                dq.pop_front();
                ans++;
            }
            dq.pop_front();
        } else {
            for (int j=1; j<=right; j++) {
                dq.push_front(dq.back());
                dq.pop_back();
                ans++;
            }
            dq.pop_front();
        }
    }
    cout << ans << '\n';
    return 0;
}