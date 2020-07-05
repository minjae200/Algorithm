#include <iostream>
#include <cmath>
using namespace std;

const int MAX = 16;
int N, res;
int chess[MAX];

void DFS(int pos)
{
    if(pos==N){
        res++;
        return;
    }
    for(int i=0; i<N; i++){
        bool check = true;
        for(int j=0; j<pos; j++){
            if(chess[j]==i || abs(pos-j) == abs(i-chess[j])){
                check = false;
                break;
            }
        }
        if(check){
            chess[pos] = i;
            DFS(pos+1);
        }
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>N;
    DFS(0);
    cout<<res<<'\n';
    return 0;
}