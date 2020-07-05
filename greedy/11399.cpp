#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> P;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i=1; i<=N; i++){
        int data; cin>>data;
        P.push_back(data);
    }
    sort(P.begin(), P.end(), less<int>());
    int gop = P.size();
    int res = 0;
    for(int i=0; i<P.size(); i++){
        res += (P[i] * gop);
        gop--;
    }
    cout<<res<<'\n';
    return 0;
}