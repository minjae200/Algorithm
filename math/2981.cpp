#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int get_gcd(int a, int b)
{
    if(b==0) return a;
    return get_gcd(b, a%b);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    int N; cin>>N;
    vector<int> v;
    for(int i=0; i<N; i++){
        int data; cin>>data;
        v.push_back(data);
    }
    sort(v.begin(), v.end());
    int gcd = v[1] - v[0];
    for(int i=2; i<N; i++){
        gcd = get_gcd(gcd, v[i]-v[i-1]);
    }
    vector<int> result;
    for(int i=2; i*i<=gcd; i++){
        if(gcd % i == 0){
            result.push_back(i);
            result.push_back(gcd/i);
        }
    }
    result.push_back(gcd);
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	cout << "\n";
    return 0;
}