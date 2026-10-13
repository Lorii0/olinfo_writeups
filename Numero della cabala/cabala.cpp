#include<bits/stdc++.h>
using namespace std;

int M;
int N;
int solve(string num,int n){ 
    int res=stoll(num)%M;
    if(n==N)return res;

    char last=num.back();
    if(last!='3')res=max(res,solve(num+'3',n+1));
    if(last!='6')res=max(res,solve(num+'6',n+1));
    if(last!='9')res=max(res,solve(num+'9',n+1));

    return res;
}
int main(){ 
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int caso;cin>>caso;
    for(int t=1;t<=caso;t++){ 
        int n,m;
        cin>>n>>m;
        M=m;
        N=n;
        int res=max(solve("3",1),max(solve("6",1),solve("9",1)));

        cout <<res<<" ";
    }
}