#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

typedef pair<int,int> pl;

void mincammino(int N, int M, vector<int> X, vector<int> Y, vector<int>
P, vector<int>& D){ 
    vector<vector<pl>>adj(N);
    for(int i=0;i<M;i++) adj[X[i]].push_back({Y[i],P[i]});
    for(int i=0;i<N;i++)D[i]=INT_MAX;
    vector<int>d(N,INT_MAX);
    d[0]=0;
    priority_queue<pl,vector<pl>,greater<pl>>q;
    q.push({0,0});

    while(!q.empty()){ 
        auto[dist,node]=q.top();
        q.pop();

        if(dist > d[node]) continue;

        for(auto curr: adj[node]){
            if(dist+curr.second < d[curr.first]){ 
                d[curr.first]=dist+curr.second;
                q.push({d[curr.first],curr.first});
            }
        }
    }
    for (int i = 0; i < N; i++)
		D[i] = d[i]==INT_MAX?-1:d[i];
}