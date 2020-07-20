#if 0
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
int N, M, K;
vector<ll> v;
vector<ll> tree;

ll init(int node, int start, int end)
{
    if (start == end) {
        tree[node] = v[start];
    } else {
        return tree[node] = init(node*2, start, (start+end)/2) + \
                            init(node*2+1, (start+end)/2 + 1, end);
    }
}

void update(int node, int start, int end, int index, ll diff)
{
    if (index < start || index > end) return;
    tree[node] = tree[node] + diff;
    if (start != end) {
        update(node*2, start, (start+end)/2, index, diff);
        update(node*2+1, (start+end)/2+1, end, index, diff);
    }
}

ll sum(int node, int start, int end, int left, int right)
{
    if (left > end || right < start) return 0;
    if (left <= start && end <= right) return tree[node];
    return sum(node*2, start, (start+end)/2, left, right) + \
            sum(node*2+1, (start+end)/2+1, end, left, right);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;
    for (int i=0; i<N; i++) {
        int data; cin >> data;
        v.push_back(data);
    }
    int h = (int)ceil(log2(N));
    int tree_size = 1 << (h+1);
    tree.resize(tree_size);
    init(1, 0, N-1);
    M += K;
    for (int i=0; i<M; i++) {
        int a; cin >> a;
        if (a==1) {
            int b; ll c;
            cin >> b >> c;
            b -= 1;
            ll diff = c - v[b];
            v[b] = c;
            update(1, 0, N-1, b, diff);
        } else if (a==2) {
            int b, c;
            cin >> b >> c;
            cout << sum(1, 0, N-1, b-1, c-1) << '\n';
        }
    }
    return 0;
}
#endif

#include <iostream>
#include <vector>
using namespace std;

vector<long long> v;
vector<long long> tree;
int N, M, K;

long long sum(int i)
{
    long long ans = 0;
    while (i > 0) {
        ans += tree[i];
        i -= (i & -i);
    }
    return ans;
}

void update(int i, long long diff)
{
    while (i < tree.size()) {
        tree[i] += diff;
        i += (i & -i);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);

    cin >> N >> M >> K;
    M += K;
    v.resize(N+1); tree.resize(N+1);
    for (int i=1; i<=N; i++) {
        cin >> v[i];
        update(i, v[i]);
    }
    while (M--) {
        int a; cin >> a;
        if (a == 1) {
            int b; cin >> b;
            long long c; cin >> c;
            long long diff = c - v[b];
            v[b] = c;
            update(b, diff);
        }
        else if (a == 2) {
            int b, c;
            cin >> b >> c;
            cout << sum(c) - sum(b-1) << '\n';
        }
    }
    return 0;
}