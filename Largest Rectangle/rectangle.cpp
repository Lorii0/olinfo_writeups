#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n;
  fin >> n;

  vector<int> v(n);

  for(int i = 0; i < n; i++)fin >> v[i];

  sort(v.begin(), v.end(),greater<int>());

  long area = 1;
  int m = 0;
  for(int i = 0; i < n-1; i++){

    if(v[i] == v[i+1]){

      area *= v[i];
      m++;
      i++;
    }

    if(m==2)break;

    if(i >=n-2)area = 0;
  }

  fout << area;
}