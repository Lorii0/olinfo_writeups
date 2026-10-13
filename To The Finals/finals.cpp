#include <bits/stdc++.h>

using namespace std;
int main() {
  
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  int p;
  int max = 0;
  int max1;
  int squad0;
  int s1,s2,s3;
  int points;

  fin >>n;
  fin >> p;

  p = p * 100;

  for(int i = 0; i<n; i++){

    fin >> s1;
    fin >> s2;
    fin >> s3;
     points = s1+s2+s3;
    
    if(i == 0) squad0 = points;
    else{
    max1 = points + p - squad0 + 1;
    if(max1 > max) max = max1;
    }
    
  }
    fout << max;
    
}
  