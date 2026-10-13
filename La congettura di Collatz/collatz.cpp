#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  int m = 1;
  
  fin >> n;

  while(n != 1){

    m++;

    if((n%2) == 0){

      n = n/2;
      
    }else if((n%2) == 1){

      n = n*3 + 1;
      
    }
  }

  fout << m; 
}
