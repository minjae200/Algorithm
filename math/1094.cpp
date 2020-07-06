#include <iostream>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int x; cin >> x;
    int r = 0;
    while(x != 0) {
        if(x % 2 == 1) r++;
        x /= 2;
    }
    cout << r << '\n';
    return 0;
}