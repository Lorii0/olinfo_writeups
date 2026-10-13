#include <bits/stdc++.h>
using namespace std;

bool solve(int x,vector<int>& S, vector<int>& A, vector<int>& B){
    int N=S.size();
    vector<int>prefix(N+2,0);
    prefix[N]=1;
    for(int i=N-1;i>=0;i--){
        if(S[i]>x){
            prefix[i]=prefix[i+1];
            continue;
        }
        prefix[i]=prefix[i+1];
        if(prefix[i+A[i]]-prefix[i+1+B[i]]>0)prefix[i]++;
    }
    if(prefix[0]-prefix[1]>0)return true;

    return false;
}
int salta(int N, vector<int> S, vector<int> A, vector<int> B){

    if(N==1)return S[0];

    int l=0;
    int r=1000000;
    while(l<r){
        int mid=(r+l)/2;
        bool res=solve(mid,S,A,B);
        if(res)
            r=mid;
        else
            l=mid+1;
    }
    return l;
}
