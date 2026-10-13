#include <bits/stdc++.h>
using namespace std;

vector<vector<char>>v;
vector<vector<int>>dp;
int N,M;
int solve(int n,int m){ 
    if(v[n][m]=='+')return 0;
    if(n==N-1&&m==M-1)return 1;
    if(dp[n][m]!=-1)return dp[n][m];

    int res1=0,res2=0;
    if(n!=N-1)res1=solve(n+1,m);
    if(m!=M-1)res2=solve(n,m+1);
    return dp[n][m]=res1+res2;
}
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n,m;cin>>n>>m;
    N=n;
    M=m;
    
    v.resize(n,vector<char>(m));
    dp.resize(n,vector<int>(m,-1));
    for(int i=0;i<n;i++){ 
        for(int j=0;j<m;j++){
            cin>>v[i][j];
        }
    }
    cout<<solve(0,0)<<endl;
}