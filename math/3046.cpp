#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int r, s;
    cin >> r >> s;
    cout << 2*s-r << '\n';
    return 0;
}