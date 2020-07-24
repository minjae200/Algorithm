#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    int day, ans =0;
    cin >> day;
    for (int i=1; i<=5; i++) {
        int car; cin >> car;
        if (car == day) ans++;
    }
    cout << ans << '\n';
    return 0;
}