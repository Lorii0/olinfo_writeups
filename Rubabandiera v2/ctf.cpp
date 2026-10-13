#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int x;
  fin >> x;

  for (int i = 0; i < x; i++) {
    long long n, copy;
    fin >> n;
    copy = n;
    n *= 2;

    for (long long j = 1; j < n; j *= 2) {
      n -= n % (j * 2);
    }

    fout << (~n & ((copy << 1) | 1)) << "\n";
  }
}
