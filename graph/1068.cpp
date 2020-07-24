#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 50;
int N, deleteNode, root;
vector<int> tree[MAX];
int node[MAX];
bool visited[MAX];

void DFS(int parent)
{
    if (visited[parent]) return;
    visited[parent] = true;
    node[parent] = -1;
    for (int i=0; i<tree[parent].size(); i++) {
        int child = tree[parent][i];
        DFS(child);
    }
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("input.txt", "r", stdin);
    cin >> N;
    for (int i=0; i<N; i++) {
        int parent; cin >> parent;
        if (parent == -1) {
            root = i;
            continue;
        }
        tree[parent].push_back(i);
        node[parent]++;
    }
    cin >> deleteNode;
    memset(visited, false, sizeof(visited));
    int parent = -1;
    for (int i=0; i<N; i++) {
        for (int j=0; j<tree[i].size(); j++) {
            if (tree[i][j] == deleteNode) parent = i;
        }
    }
    node[parent]--;
    DFS(deleteNode);
    int leaf = 0;
    for (int i=0; i<N; i++) {
        if (node[i] == 0) leaf++;
    }
    cout << leaf << '\n';
    return 0;
}