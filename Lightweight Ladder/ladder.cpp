#include <bits/stdc++.h>
using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int l = 0;
  int n;
  int ladder;
  int lenght;

  fin >> n;

  vector<int> array(n);

  for (int i = 0; i < n; i++)
    fin >> array[i];

  for (int i = 0; i < n; i++) {

    if (i == 0)
      lenght = array[i];
    else
      lenght = array[i] - array[i - 1];

    if (lenght > l) {
      l = lenght;
    }
  }

  fout << l;
}