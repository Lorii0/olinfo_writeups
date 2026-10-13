#include <bits/stdc++.h>

using namespace std;
int main() {
  
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  int pointer = 0;
  

  fin >> n;

  
  char jumps[n];

  fin >> jumps;

  for(int i = 0; i < n; i++){

    if(jumps[i] == 'L') pointer --;
    if(jumps[i] == 'R') pointer ++;
  }

  if(pointer < 0) pointer = -pointer;
  
  fout << pointer;
}




  
  
