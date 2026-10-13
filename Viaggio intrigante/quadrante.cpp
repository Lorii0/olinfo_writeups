#include <bits/stdc++.h>
using namespace std;

bool solve(int prx,vector<pair<int,int>>& v2){
    if(prx==0)return 1;

    vector<pair<int,int>>v(prx);
    for(int i=0;i<prx;i++)v[i]=v2[i];
    sort(v.begin(),v.end());

    for(int j=0;j<v.size()-1;j++)
        if(v[j].second>v[j+1].second)return 0;
    
    return 1;
}
int main(){ 
    ofstream cout("output.txt");
    int caso;cin>>caso;
    for(int t=1;t<=caso;t++){ 
        int n;cin>>n;
        vector<pair<int,int>>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i].first;
            cin>>v[i].second;
        }
        int ans=0;
        int l=0,r=n-1;
        while(l<=r){ 
            int mid=(l+r)/2;
            int res=solve(mid,v);
            if(l==r){
                ans= (res==1 ? mid : mid-1);
                break;
            }
            if(res){
                l=mid+1;
                ans=mid;
            }
            else r=mid-1;
        }
        cout<<"Case #"<<t<<": "<<ans<<endl;        
    }
}