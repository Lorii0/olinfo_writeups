#include<bits/stdc++.h>
using namespace std;

int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");

	int n,p;
    cin>>n>>p;
    int ans=0;
    int curr=1;

    while(n>0){ 
        int take =min(n,curr);
        ans+=take;
        n-=take;
        if(n==0)break;

        if(n>=p-1)n-=p-1;
        else{
            ans+=p-1;
            n=0;
        }
        curr++;
    }
    cout<<ans<<endl;
}