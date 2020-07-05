#include <iostream>
using namespace std;

const int coin[] = {500, 100, 50, 10, 5, 1};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int N; cin >> N;
    N = 1000 - N;
    int cnt = 0;
    int coinIndex = 0;
    while(1) {
        if (N <=0 ) break;
        if (N < coin[coinIndex]) {
            coinIndex++;
            continue;
        }
        N -= coin[coinIndex];
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}