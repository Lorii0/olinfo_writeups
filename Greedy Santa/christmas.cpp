#include <bits/stdc++.h>
using namespace std;

int K;
int N;
int solve(int n,int p,vector<int>& v,vector<vector<int>>& dp){
    if(p>=K||n==N)return p;
    if(dp[n][p]!=-1)return dp[n][p];

    int res1=solve(n+1,p,v,dp);
    int res2=solve(n+1,p+v[n],v,dp);

    if(res1<K){
        if(res2>=K)dp[n][p]=res2;
        else dp[n][p]=max(res1,res2);
    }else if(res2<K){ 
        if(res1>=K)dp[n][p]=res1;
        else dp[n][p]=max(res1,res2);
    }else dp[n][p]=min(res1,res2);

    return dp[n][p];
}
int main(){

    int n,k;cin>>n>>k;
    N=n;
    K=k;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>> v[i];
    vector<vector<int>>dp(n,vector<int>(k,-1));

    cout <<solve(0,0,v,dp)<<endl;

}