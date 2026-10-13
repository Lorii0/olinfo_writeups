#include <bits/stdc++.h>
using namespace std;

int main(){
    ofstream fout("output.txt");
    int t;
    cin >> t;
    for(int caso=1; caso<=t; caso++){
        long long n;cin>>n;
        long long ans=0;
        while(n>2){
            if(n%2==0){
                n/=2;
            }else{
                n++;
            }
            ans++;
        }
        fout << "Case #"<<caso<<": "<<ans+1<< endl;
    }
}