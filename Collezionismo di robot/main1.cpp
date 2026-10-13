#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");
  int t;
  fin >> t;

  for (int T = 1; T <= t; T++) {
    int n;
    fin >> n;
    int k;
    fin >> k;

    vector<int> m(n);

    for (int i = 0; i < n; i++)
      fin >> m[i];

    sort(m.begin(), m.end());

    vector<int> discrepanze(n - 1);

    for (int i = 0; i < n - 1; i++) {
      discrepanze[i] = m[i + 1] - m[i];
    }

    sort(discrepanze.begin(), discrepanze.end());

    long long somma = 0;

    for (int i = 0; i < n - k; i++)
      somma += discrepanze[i];

    fout << "Case #" << T << ": " << somma << endl;
  }
}