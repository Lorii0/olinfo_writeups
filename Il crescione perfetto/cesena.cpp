#include <bits/stdc++.h>
using namespace std;

typedef pair<long long, int> pr;

int visita(int N, int M, int K, vector<int> S, vector<int> A, vector<int> B, vector<int> T) {
    vector<vector<pr>> adj(N);
    for (int i = 0; i < M; i++) {
        adj[A[i]].emplace_back(T[i], B[i]);
        adj[B[i]].emplace_back(T[i], A[i]);
    }
    vector<int>dist(N,0);
    priority_queue<pr, vector<pr>> pq;
    dist[0] = N;
    pq.emplace(LONG_MAX , 0);
    while (!pq.empty()) {
        long long d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d < dist[u]) continue;
        for (auto cur : adj[u]) {
            long long weight = cur.first;
            int v = cur.second;
            if (min(d,weight) > dist[v]) {
                dist[v] = min(d,weight);
                pq.emplace(dist[v], v);
            }
        }
    }
    vector<int>res(K);

    for(int i=0;i<K;i++){
        res[i]=dist[S[i]];
    }
    sort(res.begin(), res.end());

    int ans=0;
    int c=0;
    for(int i=0;i<K;i++){
        if(res[i]>c){
            ans++;
            c++;
        }
    }

    return ans;

}