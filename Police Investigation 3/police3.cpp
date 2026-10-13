#include <bits/stdc++.h>
using namespace std;

map<pair<int,int>,int> dp;
int solve(int n,int skipped,vector<int>& v){ 
    if(n>=v.size())return 0;
    if(dp.count({n,skipped})) return dp[{n,skipped}];
    int no=INT_MAX,yes=INT_MAX;

    if(skipped)yes=solve(n+1,0,v);
    no=solve(n+1,1,v)+v[n];
    return dp[{n,skipped}]=min(no,yes);

}
int main(){ 
    int n;cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    cout<<solve(0,1,v)<<endl;
}