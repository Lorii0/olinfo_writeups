#include <bits/stdc++.h>
using namespace std;

int main(){ 
    int n,k;
    cin>>n>>k;
    vector<int>v(n+1);
    for(int i=1;i<=n;i++)cin>>v[i];
    int ans=0;
    int i=1;
    while(i!=k){ 
        ans++;
        if(ans>n){ 
            ans=-1;
            break;
        }
        i=v[i];
    }
    cout<<ans;
}