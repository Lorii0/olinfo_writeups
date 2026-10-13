#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  fin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; i++) {
    fin >> v[i];
  }

  sort(v.begin(), v.end());

  long s = 1;

  long sum = 0;

  for (int i = 0; i < n; i++) {

    sum += s;

    if (v[i + 1] > v[i] && i != n - 1) {
      s++;
    }
  }
  fout << sum;
}