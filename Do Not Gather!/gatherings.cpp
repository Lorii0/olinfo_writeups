#include <bits/stdc++.h>

using namespace std;

ifstream fin = ifstream("input.txt");
ofstream fout = ofstream("output.txt");

int main() {
  int n, d;
  fin >> n >> d;

  vector<int> v(n);

  for (int i = 0; i < n; ++i)
    fin >> v[i];

  long long sum = 0;
  int dx = 0;
  for (int sx = 0; sx < n - 1; sx++) {

    while (v[dx] - v[sx] < d && dx < n) {
      dx++;
    }
    sum += dx - sx - 1;
  }

  fout << sum;

  return 0;
}
