#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pr;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int> P, vector<long long>& D) {
    vector<vector<pr>> adj(N);
    for (int i = 0; i < M; i++) {
        adj[X[i]].emplace_back(P[i], Y[i]);
    }
    for (int i = 0; i < N; i++) {
        D[i]=LONG_LONG_MAX;
    }
    priority_queue<pr, vector<pr>, greater<pr>> pq;
    D[0] = 0;
    pq.emplace(0, 0);
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > D[u]) continue;
        for (auto cur : adj[u]) {
            long long weight = cur.first;
            int v = cur.second;
            if (D[u] + weight < D[v]) {
                D[v] = D[u] + weight;
                pq.emplace(D[v], v);
            }
        }
    }
     for (int i = 0; i < N; i++) {
        if (D[i] == LONG_LONG_MAX) {
            D[i] = -1;
        }
    }
}
