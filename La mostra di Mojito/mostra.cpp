#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");


int dp[1005][1005];
int n,m;

int solve(vector<int>vis,vector<int>guid,int v,int g){

    if(dp[v][g]!=0)return dp[v][g];
    if(g==0)return v;   
    if(v==0)return 0;
    
    	if(guid[g-1]>vis[v-1]){
    		dp[v][g] =	max(solve(vis,guid,v,g-1),max(solve(vis,guid,v-1,g)+1,solve(vis,guid,v-1,g-1)+2));
		}else{
			dp[v][g] =	max(solve(vis,guid,v,g-1),solve(vis,guid,v-1,g)+1);
		}

    return dp[v][g];
}

int main(){
    int t;
    fin>>t;

    for(int T=1;T<=t;T++){  

        fin>>n>>m;
        vector<int> vis(n);
        
        vector<int> guid(m);
        

        for(int i=0;i<n;i++)fin>>vis[i];
        reverse(begin(vis),end(vis));
        for(int i=0;i<m;i++)fin>>guid[i];
        reverse(begin(guid),end(guid));

        memset(dp,0,sizeof dp);

        int res=solve(vis,guid,n,m);

        if(res<n)res=n;
        fout<<"Case"<<" #"<<T<<": "<<res<<endl;
    }
   

}