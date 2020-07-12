#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
vector<int> weight;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N;
    for (int i=0; i<N; i++) {
        int data; cin >> data;
        weight.push_back(data);
    }

    int ans = 0;
    sort(weight.begin(), weight.end());
    for (int i=0; i<N; i++) {
        ans = max(ans, weight[i] * (N-i));
    }
    cout << ans << '\n';
    return 0;
}