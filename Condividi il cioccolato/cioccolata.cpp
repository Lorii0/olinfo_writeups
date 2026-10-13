#include <bits/stdc++.h>
using namespace std;

int main(){
    
    ofstream fout("output.txt");
    int t;
    cin >> t;

    for(int caso=0; caso<t; caso++){
        long long n, m, k;
        cin >> n >> m >> k;

        long long r= abs(n-m);

        if(k<=r){
            fout << "Case #"<<caso+1<<": "<<(n*m) -(min(n,m)*k) << endl;
            continue;
        }

        if(n<m)m=n;
        else n=m;

        k -= r;

        if(k%2==0){
            n-=k/2;
            m-=k/2;
        }else{
            n-=k/2;
            m-=k-(k/2);
        }
        fout << "Case #"<<caso+1<<": "<<n*m << endl;
    }
}