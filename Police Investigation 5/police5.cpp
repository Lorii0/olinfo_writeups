#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  fin >> n;

  int m;
  fin >> m;

  int t;
  fin >> t;

  vector<vector<pair<int, int>>> graph(n);

  vector<vector<int>> exp(n);

  for (int i = 0; i < m; i++) {

    int from, to, cost, e;

    fin >> from >> to >> cost >> e;

    graph[from].push_back({to, cost});
    exp[from].push_back(e);
  }

  vector<long long> dist(n, INT_MAX);

  queue<int> q;

  q.push(0);

  dist[0] = 0;

  while (!q.empty()) {

    int current = q.front();

    q.pop();

    for (int i = 0; i < graph[current].size(); i++) {
      int d = dist[current] + graph[current][i].second;

      if (exp[current][i] == 1)
        if (d > t)
          continue;

      if (d < dist[graph[current][i].first]) {

        dist[graph[current][i].first] = d;

        q.push(graph[current][i].first);
      }
    }
  }

  if(dist[n - 1]==INT_MAX)fout <<-1;
  else fout << dist[n - 1];
  
}