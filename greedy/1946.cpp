#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 100000 + 1;
int N, T;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> T;
    while (T--) {
        cin >> N;
        vector<pair<int,int>> person(N+1);
        for (int i=1; i<=N; i++) {
            cin >> person[i].first >> person[i].second;
        }
        sort(person.begin(), person.end(), [](pair<int,int> a, pair<int, int> b) { return a.first < b.first; });
        int res = N;
        int bound = person[1].second;
        for (int i=1; i<=N; i++) {
            if (bound < person[i].second) {
                res--;
                continue;
            }
            bound = person[i].second;
        }
        cout << res << '\n';
    }
    return 0;
}