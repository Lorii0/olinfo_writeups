#include <bits/stdc++.h>

using namespace std;
int main() {
  
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  int max = -1;

  int s;
  int s2;

  fin >> n;


  for(int i = 0; i < n; i++){

    fin >> s;
    fin >> s2;

    int s3 = s + s2;


    if((s3 % 2) == 0){
      if(s3 > max){
        max = s3;
      }
    } 
  }
  fout << max;
}
  
  