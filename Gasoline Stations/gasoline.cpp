#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n;cin>>n;
    vector<int>p(n);
    vector<int>g(n);
    for(int i=0;i<n;i++)cin>>p[i];
    for(int i=0;i<n;i++)cin>>g[i];
    int min=p[0];
    long long ans=min*g[0];
    for(int i=1;i<n;i++){
        if(p[i]<=min)min=p[i];
        ans+=min*g[i];
    }
    cout<<ans<<endl;
}
