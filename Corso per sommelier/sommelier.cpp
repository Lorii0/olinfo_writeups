#include <bits/stdc++.h>

using namespace std;


int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<int> dp(n,1);

    for(int i=0;i<n;i++){ 
        for(int j=0;j<i-1;j++){
            if(v[i]>=v[j]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++){ 
        if(dp[i]>ans)ans=dp[i];
    }

    cout<<ans<<endl;
}