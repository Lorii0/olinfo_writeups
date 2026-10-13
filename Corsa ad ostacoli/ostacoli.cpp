#include <bits/stdc++.h>
using namespace std;

int main(){ 
    ofstream cout("output.txt");

    int t;cin>>t;
    for(int caso=1;caso<=t;caso++){ 
        int n,l,d;cin>>n>>l>>d;
        vector<int> x(n);
        vector<int> p(n);
        vector<pair<int,int>> s(n);
        for(int i=0;i<n;i++){ 
            cin>>x[i];
            cin>>p[i];
            cin>>s[i].first;
            s[i].second=i;
        }
        sort(s.begin(),s.end());
        vector<int> dp(n,INT_MIN);

        for(int i=0;i<n;i++){
            if(s[i].first>=x[s[i].second]){
                dp[i]=p[s[i].second];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                //cout<<"i: "<<i<<" j: "<<j<<" seconds: "<<abs(s[i].first-s[j].first)<<" meters: "<<abs(x[s[i].second]-x[s[j].second])<<endl;
                if(abs(s[i].first-s[j].first)>=abs(x[s[i].second]-x[s[j].second])){
                    //cout<<"yes"<< "min("<<dp[i]<<" , "<<dp[j]<<" + " <<p[s[i].second]<<" )"<<endl;
                    dp[i]=max(dp[i],dp[j]+p[s[i].second]);
                }
            }
        }

        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            ans=max(ans,dp[i]); 
        }
        cout<<"Case #"<<caso<<": "<<ans<<endl;
    }
}