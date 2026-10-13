#include <bits/stdc++.h>
using namespace std;

int main() {
    ofstream cout("output.txt");
    
    int T;
    cin >> T;
    
    for (int t = 1; t <= T; ++t) {
        int N, B;
        cin >> N >> B;
        
        vector<pair<int, int>> cpus;
        int sum_cores = 0;
        for (int i = 0; i < N; ++i) {
            int ci, pi;
            cin >> ci >> pi;
            cpus.emplace_back(ci, pi);
            sum_cores += ci;
        }
        
        vector<long long> dp(sum_cores + 1, 1e18);
        dp[0] = 0;
        
        for (auto &cpu : cpus) {
            int c = cpu.first;
            int p = cpu.second;
            for (int i = sum_cores; i >= 0; --i) {
                if (dp[i] != 1e18 && i + c <= sum_cores) {
                    if (dp[i] + p < dp[i + c]) {
                        dp[i + c] = dp[i] + p;
                    }
                }
            }
        }
        
        int ans = 0;
        for (int i = sum_cores; i >= 0; --i) {
            if (dp[i] <= B) {
                ans = i;
                break;
            }
        }
        
        cout << "Case #" << t << ": " << ans << "\n";
    }
    
    return 0;
}