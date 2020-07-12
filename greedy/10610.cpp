#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

string number;
vector<int> v;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> number;
    bool flag = false;
    int sum = 0;
    for (int i=0; i<number.size(); i++) {
        int num = number[i] - '0';
        if (num == 0) flag = true;
        sum += num;
        v.push_back(num);
    }
    if(!flag || (sum % 3 != 0)) cout << "-1" << '\n';
    else {
        sort(v.begin(), v.end(), greater<int>());
        for (int i=0; i<v.size(); i++) {
            cout << v[i];
        }
        cout << '\n';
    }

    return 0;
}