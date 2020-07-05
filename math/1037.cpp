#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    int N; cin>>N;
    vector<int> number;
    for(int i=1; i<=N; i++){
        int num; cin>>num;
        number.push_back(num);
    }
    sort(number.begin(), number.end());
    cout<<number[0] * number[N-1]<<'\n';
    return 0;
}