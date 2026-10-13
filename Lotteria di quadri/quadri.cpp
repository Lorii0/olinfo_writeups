#include <bits/stdc++.h>
using namespace std;

bool calc(vector<int> v, int b, long long k) {
  long long res = 0;
  for (int i = 0; i < b; i++) {
    res += v[i];
  }
  if (res > k)
    return false;

  for (int i = b; i < v.size(); i++) {
    res += v[i];
    res -= v[i - b];
    if (res > k)
      return false;
  }
  return true;
}

int quadri(int N, long long M, int V[]) {
  vector<int> v(N);
  for (int i = 0; i < N; i++) {
    v[i] = V[i];
  }

  int low = 0, high = N;
  while (high - low > 1) {
    int mid = (low + high) / 2;
    if (calc(v, mid, M)) {
      low = mid;
    } else {
      high = mid; 
    }
  }
  if (calc(v, high, M)) {
    return high;
  }
  return low;
}
