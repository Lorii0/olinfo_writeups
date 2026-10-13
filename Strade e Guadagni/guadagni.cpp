#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> pl;

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int caso; cin >> caso;
    for (int t = 1; t <= caso; t++) {
        int n, m; cin >> n >> m;
        vector<vector<int>> adj(n);
        vector<int> cost(n);

        for (int i = 0; i < m; i++) {
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for (int i = 0; i < n; i++) cin >> cost[i];

        vector<unordered_map<int, int>> dist(n);
        deque<pl> dq;
        dist[0][0] = 0;
        dq.push_front({0, {0, 0}});

        int res = -1;
        while (!dq.empty()) {
            auto [D, val] = dq.front(); dq.pop_front();
            auto [node, monete] = val;

            if (node == n - 1) {
                res = D;
                break;
            }

            if (dist[node].count(monete) && dist[node][monete] < D) continue;

            if (monete >= cost[node]) {
                for (int curr : adj[node]) {
                    if (!dist[curr].count(0) || D < dist[curr][0]) {
                        dist[curr][0] = D;
                        dq.push_front({D, {curr, 0}}); 
                    }
                }
            }

            for (int curr : adj[node]) {
                if (!dist[curr].count(monete + 1) || D + 1 < dist[curr][monete + 1]) {
                    dist[curr][monete + 1] = D + 1;
                    dq.push_back({D + 1, {curr, monete + 1}}); 
                }
            }
        }

        cout << "Case #" << t << ": " << res << endl;
    }
}
