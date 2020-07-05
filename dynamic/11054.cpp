#include <iostream>
using namespace std;

const int MAX = 1000 + 1;
int N;
int right_cache[MAX], left_cache[MAX], number[MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i=1; i<=N; i++){
        cin>>number[i];
    }
    fill(right_cache, right_cache+MAX, 1);
    fill(left_cache, left_cache+MAX, 1);
    for(int i=2; i<=N; i++){
        for(int j=1; j<i; j++){
            if(number[i] > number[j]){
                right_cache[i] = max(right_cache[i], right_cache[j]+1);
            }
        }
    }
    for(int i=N; i>=1; i--){
        for(int j=N; j>=i; j--){
            if(number[i] > number[j]){
                left_cache[i] = max(left_cache[i], left_cache[j]+1);
            }
        }
    }
    int res = 0;
    for(int i=1; i<=N; i++){
        right_cache[i] += left_cache[i] - 1;
        res = max(res, right_cache[i]);
    }
    cout<<res<<'\n';
    return 0;
}