#include <bits/stdc++.h>
using namespace std;


vector<vector<int>>dp;
vector<int>P;
int K,N;

int solve(int i, int current_sum) {
    if (current_sum >= K) 
        return current_sum;
    if (i == N) 
        return INT_MAX;
    if(dp[i][current_sum]!=-1)return dp[i][current_sum];

    int  take = solve(i + 1, current_sum + P[i]);
    int  not_take = solve(i + 1, current_sum);

    return dp[i][current_sum] = min(take, not_take);
}

int mangia(int N, int K, int P[]){
    return solve(0,0);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n, k;
    cin >> n >> k;
    N=n;
    K=k;
    P.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }
    dp.resize(n,vector<int>(k+1,-1));
    cout << mangia(0,0,{}) << endl;
    return 0;
}