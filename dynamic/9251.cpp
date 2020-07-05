#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
string s1, s2;
int cache[MAX][MAX];

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin>>s1>>s2;
    int len1 = s1.length();
    int len2 = s2.length();
    for(int i=1; i<=len1; i++){
        for(int j=1; j<=len2; j++){
            cache[i][j] = max({cache[i][j-1], cache[i-1][j], 
                        cache[i-1][j-1]+(s1[i-1]==s2[j-1])});
        }
    }
    cout<<cache[len1][len2]<<'\n';
    return 0;
}