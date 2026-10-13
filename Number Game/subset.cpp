#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<long long>v(n);
    for(int i=0;i<n;i++)cin>>v[i];

    vector<int>dp(n,0);
    sort(v.begin(), v.end());

    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){ 
            if(v[i]%v[j]==0){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int ans =INT_MIN;
    for(int i=0;i<n;i++){ 
        if(dp[i]>ans)ans=dp[i];
    }

    cout<<ans+1<<endl;
}