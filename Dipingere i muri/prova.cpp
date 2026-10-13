#include <bits/stdc++.h>
using namespace std;
int main(){ 
    ofstream cout("output.txt");
    int caso;cin>>caso;
    for(int t=1;t<=caso;t++){ 
        int n,q;
        cin>>n>>q;
        int ans=0;
        for(int i=0;i<q;i++){ 
            int a;cin>>a;
            if(ans+a>n)ans-=(ans+a)-n;
            ans++;
        }

        cout<<"Case #"<<t<<": "<<ans<<endl;

        
    }
}