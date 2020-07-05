#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX = 100000 + 1;
int N;
vector<pair<int,int>> room;

bool cmp(pair<int,int> a, pair<int,int> b)
{
    if(a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i=1; i<=N; i++){
        pair<int,int> data;
        cin>>data.first>>data.second;
        room.push_back(data);
    }
    sort(room.begin(), room.end(), cmp);
    int res = 0;
    int end_time = 0;
    for(int i=0; i<room.size(); i++){
        if (end_time <= room[i].first){
            end_time = room[i].second;
            res++;
        }
    }
    cout<<res<<'\n';
    return 0;
}