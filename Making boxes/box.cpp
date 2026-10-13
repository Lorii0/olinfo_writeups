#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;

int main(){

    int n;cin>>n;
    vector<int>aree(n+1);
    for(int i=1;i<=n;i++){
        int div=1;
        int res=-1;
        while((div*div)<=i){
            if(i%div==0)res=div;
            div++;
        }

        int res2=i/res;

        aree[i]=2*res+2*res2;
    }   

    vector<int> dp(n+1,1e9);
    dp[0]=0;

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
                dp[j]=min(dp[j],dp[j-i]+aree[i]);
            
        }
    }
    cout<<dp[n]; 
}