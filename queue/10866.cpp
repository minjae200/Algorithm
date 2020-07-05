#include <iostream>
#include <deque>
#include <string>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int N; cin >> N;
    deque<int> q;
    for (int i=0; i<N; i++) {
        string cmd;
        cin >> cmd;
        if(!cmd.compare("push_front")) {
            int data; cin >> data;
            q.push_front(data);
        } else if (!cmd.compare("push_back")) {
            int data; cin >> data;
            q.push_back(data);
        } else if (!cmd.compare("pop_front")) {
            if (q.empty()) {
                cout << -1 << endl;
                continue;
            }
            int data = q.front();
            q.pop_front();
            cout << data << endl;
        } else if(!cmd.compare("pop_back")) {
            if (q.empty()) {
                cout << -1 << endl;
                continue;
            }
            int data = q.back();
            q.pop_back();
            cout << data << endl;
        } else if(!cmd.compare("size")) {
            cout << q.size() << endl;
        } else if(!cmd.compare("empty")) {
            cout  << q.empty() << endl;
        } else if (!cmd.compare("front")) {
            if (q.empty()) {
                cout << -1 << endl;
                continue;
            }
            cout << q.front() << endl;
        } else if (!cmd.compare("back")) {
            if (q.empty()) {
                cout << -1 << endl;
                continue;
            }
            cout << q.back() << endl;
        }

    }
    return 0;
}