#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n;fin>>n;

  vector<pair<vector<int>,int>>v(n);

  vector<bool>vis(n,false);

  queue<pair<int,int>>q;

  for(int i=0;i<n;i++){
    int j;int k;
    fin>>j>>k;
    v[i].second=k;

    if(k==0){
        q.push({i,0});
        vis[i]=true;
    }
    for(int m=0;m<j;m++){
        int temp;fin>>temp;
        v[temp].first.push_back(i);
    }
  }

  if(q.empty()){
    fout<<0;
    return 0;
  }

  while(!q.empty()){

    auto[idx,amici]=q.front();
    q.pop();



        for(int child: v[idx].first){

        if(!vis[child]){
            v[child].second--;
            if(v[child].second<=0){
                vis[child]=true;
                q.push({child,v[child].second});
            }
        }
      }

  }

  int count=0;

  for(int i=0;i<n;i++){
    if(vis[i])count++;
  }

  fout<<count;



}
