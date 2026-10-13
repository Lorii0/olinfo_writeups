#include <bits/stdc++.h>

using namespace std;

map<pair<int, int>, int> dp;
int N;
int solve(vector<int>nums){ 
    int res1=0,res2=0;
    int temp;
    for(int n :nums){ 
        temp=max(res1+n,res2);
        res1=res2;
        res2=temp;
    }
    return res2;
}
int main(){
    ifstream cin("input.txt");
    ofstream cout("output.txt");

    int n;cin>>n;
    N=n;
    vector<int> v(n);

    for(int i=0;i<n;i++)cin>>v[i];
    if(n==1){
        cout<<v[0]<<endl;
        return 0;
    }

    vector<int> r1=v;
    vector<int> r2=v;
    r1.pop_back();
    r2.erase(r2.begin());
    cout<<max(solve(r1),solve(r2));
    
    
}