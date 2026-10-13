#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream cout("output.txt");
    int t;cin>>t;
    for(int caso=1;caso<=t;caso++){
        int k;cin>>k;
        int a,b,c,d;cin>>a>>b>>c>>d;
        
        while(1){
            if(k<=a){
                a-=k;
                d+=k;
                break;
            }else{
                k-=a;
                d+=a;
                a=0;
            }

            if(k<=b){
                b-=k;
                d+=k;
                break;
            }else{
                k-=b;
                d+=b;
                b=0;
            }

            if(k<=c){
                c-=k;
                d+=k;
                break;
            }else{
                k-=c;
                d+=c;
                c=0;
                break;
            }
        }
        cout<< "Case# "<<caso<<": "<<1*a+2*b+3*c+4*d<<endl;
        
    }
}