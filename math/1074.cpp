#include<iostream>
#include<cmath>
 
using namespace std;
int res, n, r, c;
 
void Z(int x, int y, int j) {
    if (x == r && y == c) {
        cout << res << endl;
        return;
    }
 
    if (r < x + j && r >= x && c < y + j && c >= y) {
        Z(x, y, j / 2);
        Z(x, y + j / 2, j / 2);
        Z(x + j / 2, y, j / 2);
        Z(x + j/2, y + j/2, j / 2);
    }
    else {
        res += j* j;
    }
 
}
 
int main() {
    res = 0;
    cin >> n >> r >> c;
    Z(0, 0, pow(2, n));
    return 0;
}
