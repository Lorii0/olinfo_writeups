#include <bits/stdc++.h>
using namespace std;

typedef pair<long long,long long> ll;
long long estrai(int N, long long K, vector<int> A, vector<int> Q) {
	priority_queue<ll,vector<ll>,greater<ll>> q;
    long long sum = 0;
    long long time = 0;
    long long ans = INT64_MAX;
    for(int i=0;i<N;i++){
        time += A[i];
        sum += (long long)Q[i]* (long long)A[i];
        if(A[i]-1 > 0)q.push({Q[i],A[i]-1});
        long long extra;

        while(sum>K){
            if(q.empty()) break;
            extra = sum - K;
            ll cur = q.top();
            long long rm = extra / cur.first;
            if(rm == 0)break;
            q.pop();
            if(rm<cur.second){
                cur.second -= rm;
                q.push(cur);
                sum -= cur.first * rm;
                time -= rm;
            }else{
                sum -= cur.first * cur.second;
                time -= cur.second;
            }
        }

        if(sum >= K && time < ans)ans = time;
    }
    return ans;
}
