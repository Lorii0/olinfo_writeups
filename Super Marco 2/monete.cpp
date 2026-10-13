#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n;
  fin >> n;

  int m;
  fin >> m;

  vector<bool> visited(n, false);

  vector<int> v(n);

  for (int i = 0; i < n; i++) fin >> v[i];
    
  vector<vector<int>> graph(n);

  for (int i = 0; i < m; i++) {

    int from, to;

    fin>>from>>to;

    graph[from].push_back(to);
    graph[to].push_back(from);
  }

  queue<int>q;

  q.push(0);

  visited[0]=true;

  int sum = 0;

  sum+= v[0];

  while (!q.empty()) {

    int current = q.front();

    q.pop();

    for(int a: graph[current]) {

      if(!visited[a]){

        visited[a]=true;
        sum += v[a];

        q.push(a);
      }
    }

  
  }

  fout << sum;

  



  
}