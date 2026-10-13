#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n,m,k;
  fin >> n>>m>>k;

  vector<int> dist1(n,-1);
  vector<int> dist2(n,-1);

  vector<vector<int>> g(n);

  vector<int>shops;

  for (int i = 0; i < k; i++){
    int s;
    fin>>s;
    shops.push_back(s-1);
  }

  for (int i = 0; i < m; i++) {

    int from, to;

    fin>>from>>to;

    from--;to--;

    g[from].push_back(to);
    g[to].push_back(from);
  }


  queue<int>q;

  q.push(0);

  dist1[0]=0;

  while(!q.empty()){
    int node=q.front();
    q.pop();
    for(int figlio:g[node]){
        if(dist1[figlio]==-1){
            q.push(figlio);
            dist1[figlio]=dist1[node]+1;
            }
        }
    }

  q.push(n-1);
  dist2[n-1]=0;
  while(!q.empty()){
    int node=q.front();
    q.pop();
    for(int figlio:g[node]){
        if(dist2[figlio]==-1){
            q.push(figlio);
            dist2[figlio]=dist2[node]+1;
            }
        }
    }

      int min1=INT_MAX;

    for(int i=0;i<k;i++){
        if(dist1[shops[i]]+dist2[shops[i]]<min1){
            min1=dist1[shops[i]]+dist2[shops[i]];
        }


    }

    fout<<min1;
}

