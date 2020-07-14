#include <iostream>
#include <vector>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    int tc = 3;
    while(tc--) {
        int cnt = 0;
        for (int i=0; i<4; i++) {
            int data;
            cin >> data;
            if (data) cnt ++;
        }

        switch(cnt) {
        case 0:
            cout << "D" << '\n';
            break;
        case 1:
            cout << "C" << '\n';
            break;
        case 2:
            cout << "B" << '\n';
            break;
        case 3:
            cout << "A" << '\n';
            break;
        case 4:
            cout << "E" << '\n';
            break;
        }
    }
    return 0;
}