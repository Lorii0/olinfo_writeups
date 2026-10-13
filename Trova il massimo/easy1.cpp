#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;

  fin >> n;

  vector<int> vettore(n);

  for (int i = 0; i < n; i++)fin >> vettore[i];

  int max = INT_MIN;

  for (int i = 0; i < n; i++){
    if(vettore[i] > max)max = vettore[i];
  }

  fout<<max;
  
}
