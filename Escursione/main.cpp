#include <bits/stdc++.h>

using namespace std;

using pli=pair<int,pair<int,int>>;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int x,y;
    fin>>x>>y;

    vector<vector<int>>v(x,vector<int>(y));

    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            fin>>v[i][j];
        }

    }

    vector<vector<bool>>vis(x,vector<bool>(y,false));

    priority_queue<pli,vector<pli>, greater<pli>>pq;

    pq.push({0,{0,0}});


    int res=-1;
    int diff;
    while(!pq.empty()){

        pli curr=pq.top();
        pair<int,int>pos=curr.second;
        int dist=curr.first;
        pq.pop();
        if(vis[pos.first][pos.second])continue;

        vis[pos.first][pos.second]=true;

        if(pos.first==x-1&&pos.second==y-1){
            res=dist;
            break;
        }

        if(pos.first!=0&&!vis[pos.first-1][pos.second]){


            diff=max(dist,abs(v[pos.first-1][pos.second]-v[pos.first][pos.second]));
            pq.push({diff,{pos.first-1,pos.second}});
        }

        if(pos.first!=x-1&&!vis[pos.first+1][pos.second]){


            diff=max(dist,abs(v[pos.first+1][pos.second]-v[pos.first][pos.second]));
            pq.push({diff,{pos.first+1,pos.second}});
        }

        if(pos.second!=0&&!vis[pos.first][pos.second-1]){


            diff=max(dist,abs(v[pos.first][pos.second-1]-v[pos.first][pos.second]));
            pq.push({diff,{pos.first,pos.second-1}});
        }
        if(pos.second!=y-1&&!vis[pos.first][pos.second+1]){


            diff=max(dist,abs(v[pos.first][pos.second+1]-v[pos.first][pos.second]));
            pq.push({diff,{pos.first,pos.second+1}});
        }

    }









    fout << "Case #" << t << ": " << res<< endl;
  }



}
