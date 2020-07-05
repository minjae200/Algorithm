#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 90 + 1;
int n;
long long fibo[MAX];

long long solve(int num)
{
    if(num <= 1) return num;
    long long &ret = fibo[num];
    if(ret != -1) return ret;
    return ret = solve(num-1) + solve(num-2);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(fibo, -1, sizeof(fibo));
    // freopen("input.txt", "r", stdin);
    cin>>n;
    cout<<solve(n)<<'\n';
    return 0;
}