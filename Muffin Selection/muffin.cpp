#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n;
  int m = 0;
  int s;
  
  int max;
  int k;

  fin >> n;

  fin >> k;

  vector <int> array(n);

  for(int i = 0; i < n; i++) fin >> array[i];

  for(int i = 0; i < k; i++) m += array[i];

  max = m;
  
  for(int i = 1; i < n - k + 1; i++){
    
    m = m - array[i - 1] + array[i + k - 1];
    
    if(m > max) max = m;
    
   
  }

  fout << max;
}