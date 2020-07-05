#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int N, res = -1;
int cache[MAX], number[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>number[i];
    }
    fill(cache, cache+MAX, 1);
    for(int i=2; i<=N; i++){
        for(int j=1; j<i; j++){
            if(number[i] > number[j]){
                cache[i] = max(cache[i], cache[j]+1);
            }
        }
    }
    for(int i=1; i<=N; i++){
        res = max(res, cache[i]);
    }
    cout<<res<<'\n';
    return 0;
}