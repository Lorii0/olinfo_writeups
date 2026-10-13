#include <vector>
using namespace std;

vector<int> parent;
vector<int> rank_;
int component_count;

void inizia(int N) {
    parent.resize(N);
    rank_.resize(N, 1);
    for (int i = 0; i < N; ++i) {
        parent[i] = i;
    }
    component_count = N;
}

int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]); // Path compression
    }
    return parent[x];
}

int collega(int X, int Y) {
    int x_root = find(X);
    int y_root = find(Y);
    if (x_root == y_root) {
        return component_count;
    }
    // Union by rank
    if (rank_[x_root] < rank_[y_root]) {
        parent[x_root] = y_root;
    } else if (rank_[y_root] < rank_[x_root]) {
        parent[y_root] = x_root;
    } else {
        parent[y_root] = x_root;
        rank_[x_root]++;
    }
    component_count--;
    return component_count;
}