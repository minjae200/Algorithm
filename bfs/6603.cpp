#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


const int MAX = 13 + 1;
int K;
int number[MAX];
int result[MAX];

void DFS(int idx, int cnt)
{
    if(cnt == 6) {
        for(int i=0; i<6; i++) {
            cout << result[i] << " ";
        }
        cout << '\n';
        return;
    }

    for(int i=idx; i<K; i++) {
        result[cnt] = number[i];
        DFS(i+1, cnt+1);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    while(1){
        cin >> K;
        if (K == 0) break;
        for(int i=0; i<K; i++) {
            cin >> number[i];
        }
        DFS(0, 0);
        cout << '\n';
    }
    return 0;
}