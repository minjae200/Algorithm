#include <iostream>
#include <limits>
#include <algorithm>
using namespace std;

const int MAX = 15;
int N, number[MAX];
int operation[4];
int min_result = numeric_limits<int>::max();
int max_result = numeric_limits<int>::min();

void DFS(int cnt, int sum, int plus, int sub, int mod, int div)
{
    if(cnt==N){
        min_result = min(min_result, sum);
        max_result = max(max_result, sum);
        return;
    }
    if (plus < operation[0])
        DFS(cnt+1, sum+number[cnt], plus+1, sub, mod, div);
    if (sub < operation[1])
        DFS(cnt+1, sum-number[cnt], plus, sub+1, mod, div);
    if (mod < operation[2])
        DFS(cnt+1, sum*number[cnt], plus, sub, mod+1, div);
    if (div < operation[3])
        DFS(cnt+1, sum/number[cnt], plus, sub, mod, div+1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N;
    for(int i=0; i<N; i++){
        cin>>number[i];
    }
    for(int i=0; i<4; i++){
        cin>>operation[i];
    }
    DFS(1,number[0],0,0,0,0);
    cout<<max_result<<'\n';
    cout<<min_result<<'\n';
    return 0;
}