#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

map<pair<int,int>,int>dp;
vector<int> v;
int N;
int solve(int n,int prev){
    if(n>=N)return 0;

    if(prev!=-1&&dp.count({n,prev}))return dp[{n,prev}];

    int yes=-1,no=-1;

    no=solve(n+1,prev);

    if(prev==-1||v[n]<v[prev])
        yes=solve(n+1,n)+1;
    return dp[{n,prev}]=max(yes,no);
}

int main()
{

    int n;fin>>n;
    N=n;
    v.resize(n);
    for(int i=0;i<n;i++)fin>>v[i];

    fout<<solve(0,-1);

    return 0;

}