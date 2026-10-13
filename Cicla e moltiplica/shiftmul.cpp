#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e9 + 7;

int neg(long long x, int mod) { return ((x % mod) + mod) % mod; }
vector<int> execute(int N, int K, int D, vector<int> A) {

  if (K == 1)
    return A;

  vector<int> ex = execute(N, K / 2, D, A);
  vector<int> base(N, 1);

  for (int i = 0; i < N; i++) {
    long long formulamagica = neg(i - (long long)D * (long long)(K / 2), N);
    base[i] = ((long long)ex[i] * (long long)ex[formulamagica]) % MOD;
  }

  if (K % 2 != 0) {
    for (int i = 0; i < N; i++) {
      long long formulamagica2 = neg(i - (long long)D * (long long)(K - 1), N);
      base[i] = ((long long)base[i] * (long long)A[formulamagica2]) % MOD;
    }
  }

  return base;
}