#include <bits/stdc++.h>

using namespace std;
int main() {
  
  ifstream fin("input.txt");
  ofstream fout("output.txt");
     
  int n;
  fin >>n;
  double somma = 0;
  double media;

  vector <int> array(n);

  for(int i = 0; i < n; i++) fin >> array[i];

  for(int i = 0; i < n; i++)
  somma += array[i];

  media = somma / n;

  fout << somma << " "<< media;
}
