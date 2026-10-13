#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<int>>dp(1001,vector<int>(2,0));

int solve(int N,const int size,const int A[],const int B[],int skipped){

    if(N==size)return 0;
    if(dp[N][skipped]!=0)return dp[N][skipped];

    dp[N][skipped]=max(solve(N+1,size,A,B,1),solve(N+1,size,A,B,0)+A[N]);
    

    if(skipped){
        dp[N][skipped]=max(dp[N][skipped],solve(N+1,size,A,B,0)+B[N]);
    }

    

    return dp[N][skipped];

}
int tempo_massimo(int N, int A[], int B[]){

    dp.resize(N,vector<int>(2,0));

    return solve(0,N,A,B,1);

    

}
