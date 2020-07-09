#include <iostream>
using namespace std;

int A, B;

int rev(int n)
{
    int res = 0;
    while (n) {
        res *= 10;
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> A >> B;
    cout << rev((rev(A) + rev(B))) << '\n';
    return 0;
}