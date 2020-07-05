#include <iostream>
using namespace std;

int get_gcd(int a, int b)
{
    if(b==0) return a;
    return get_gcd(b, a%b);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int num1, num2;
    cin>>num1>>num2;

    int gcd = get_gcd(num1, num2);
    int lcm = num1*num2/gcd;
    cout<<gcd<<'\n';
    cout<<lcm<<'\n';
    return 0;
}