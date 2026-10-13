#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n;cin>>n;
    vector<int> v(n);
    vector<int> sums(n+1,0);
    vector<int>maxes(n+1,0);
    for(int i=0;i<n;i++)cin>>v[i];
    for(int i=0;i<n;i++){ 
        int t;cin>>t;
        sums[v[i]]+=t;
        maxes[v[i]]=max(maxes[v[i]],t);
    }

    int ans=0;
    for(int i=0;i<n+1;i++){ 
        ans+=sums[i]-maxes[i];
    }
    cout<<ans;

}