#include <bits/stdc++.h>
using namespace std;


vector<long long> fen;

void aggiorna(int idx, int valore) {

  while (idx <= fen.size()) {
    fen[idx] += valore;
    idx += (idx & -idx);
  }
}
long long somma(int idx) {
  long long res = 0;

  while (idx >= 1) {
    res += fen[idx];
    idx -= (idx & -idx);
  }
  return res;
}

long long paletta_sort(int N, int V[]) {

  fen = vector<long long>(N + 1, 0);
  long long int totPari = 0;
  long long int totDispari = 0;
  vector<int> even, odd;

  for (int i = 0; i <= N; i++)
    fen[i] = 0;

  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      if (V[i] % 2 != 0)
        return -1;
      else
        even.push_back(V[i]);
    } else {
      if (V[i] % 2 == 0)
        return -1;
      else
        odd.push_back(V[i]);
    }
  }
  for (int i = even.size() - 1; i >= 0; i--) {
    totPari += somma(even[i]);
    aggiorna(even[i] + 1, 1);
  }
  fen = vector<long long>(N + 1, 0);

  for (int i = odd.size() - 1; i >= 0; i--) {
    totDispari += somma(odd[i] + 1);
    aggiorna(odd[i] + 1, 1);
  }
  return totPari + totDispari;
}