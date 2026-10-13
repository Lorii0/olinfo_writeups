#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;cin>>n;
    vector<pair<int,int>> cords(n);
    map<int,vector<int>>asse_x;
    map<int,vector<int>>asse_y;
   
    for(int i=0;i<n;i++){ 
        int x,y;
        cin>>x>>y;
        cords[i]={x,y};
        asse_x[x].push_back(y);
        asse_y[y].push_back(x);
    }
    long long res=0;
    for(auto[X,Y]:cords){ 
        long long a = asse_x[X].size()-1;
        long long b = asse_y[Y].size()-1;
        res+=a*b;
    }
    cout<<res;
}