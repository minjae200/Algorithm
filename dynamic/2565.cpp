#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 500 + 1;
int N;
pair<int, int> stair[MAX];
int cache[MAX];

bool cmp(pair<int,int> a, pair<int,int> b)
{
    return a.first < b.first;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>stair[i].first>>stair[i].second;
    }
    sort(stair, stair+N+1, cmp);
    fill(cache, cache+N+1, 1);
    for(int i=2; i<=N; i++){
        for(int j=1; j<i; j++){
            if(stair[i].second > stair[j].second)
                cache[i] = max(cache[i], cache[j]+1);
        }
    }
    int res = 0;
    for(int i=1; i<=N; i++){
        res = max(res, cache[i]);
    }
    cout<<N-res<<'\n';
    return 0;
}