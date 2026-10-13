#include <bits/stdc++.h>
using namespace std;

int N;
int solve(int n,vector<int>& dp,vector<int>& v){ 
    if(n+v[n]>=N)return 1;
    if(dp[n]!=-1)return dp[n];
    
    int ans=INT_MAX;
    for(int i=1;i<=v[n];i++){ 
        ans=min(ans,solve(n+i,dp,v)+1);
    }
    return dp[n]=ans;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;cin>>n;
    N=n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<int> dp(n,-1);

    cout<<solve(0,dp,v)<<endl;
}