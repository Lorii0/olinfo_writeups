#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n;
  long long l = 0;
  long long tot = 0;

  fin >> n;
  vector <long long> array(n);
  
  
  
  for(int i = 0; i<n; i++ ) fin >> array[i];

  for(int i = 0; i<n; i++ ){

    if(array[i] > l){
      
      tot += array[i];
      l = array[i];
      
    }
  }
  cout << tot;
  
}

 