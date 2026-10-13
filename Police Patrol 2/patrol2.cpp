#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n,m,p;
    cin>>n>>m>>p;
    vector<vector<int>>adj(n);
    vector<int>c(p);
    for(int i=0;i<m;i++){ 
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0;i<p;i++)cin>>c[i];

    vector<int> dist(n,INT_MAX);
    priority_queue<pair<int,int>>q;

    dist[0]=0;
    q.push({0,0});
    while(!q.empty()){ 
        auto[sec,node]=q.top();
        sec=-sec;
        q.pop();

        if(sec> dist[node])continue;

        for(auto curr: adj[node]){ 
            if(curr!=c[(sec+1)%p]){
                if(sec+1<dist[curr]){
                    dist[curr]=sec+1;
                    q.push({-dist[curr],curr});
                }
            }else{
                if(sec+2<dist[curr]){
                    dist[curr]=sec+2;
                    q.push({-dist[curr],curr});
                }
            }
        }        
    }
    cout<<dist[n-1]<<endl;
}