#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
using namespace std;

const int MAX = 50 + 1;
int N, ans = numeric_limits<int>::max();
string X, Y;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    cin >> X >> Y;
    for (int i=0; i <=Y.length()-X.length(); i++) {
        int cnt = 0;
        for (int j=0; j<X.length(); j++) {
            if(X[j] != Y[j+i]) cnt++;
        }
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
    return 0;
}