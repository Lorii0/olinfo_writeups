#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n;
  fin >> n;

  int m;
  fin >> m;

  vector<vector<int>> graph(n);

  for (int i = 0; i < m; i++) {

    int from, to;

    fin>>from>>to;

    graph[from].push_back(to);
    graph[to].push_back(from);

  }

  vector<bool> visited(n,false);

  queue<int>q;

  int strade = 0;

  q.push(0);

  visited[0]=true;

  while(true){

    while(!q.empty()){

      int current = q.front();
      q.pop();

      for(int i = 0; i < graph[current].size(); i++){

        int j = graph[current][i];
        if(visited[j]==false){
          q.push(j);
          visited[j]=true;
        }
      }

    }

    bool finish = true;

    for(int i = 0; i < n; i++){
      if(visited[i]==false){
        finish = false;
      }
    }

    if(finish==true)break;

    for(int i = 0; i < n; i++){
      if(visited[i]==false){
        q.push(i);
        visited[i]=true;
        strade++;
        break;
      }
    }

  }


  fout << strade;
}