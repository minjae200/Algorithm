#include <iostream>
#include <queue>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int N, K;
    cin >> N >> K;
    queue<int> q;
    for ( int i=1; i<=N; i++) {
        q.push(i);
    }

    cout << "<";
    while (!q.empty()) {
        for ( int i=0; i<K-1; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << q.front();
        q.pop();
        if (!q.empty()) cout << ", ";
    }
    cout << ">";
    return 0;
}