#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n;
  fin >> n;

  int x;
  fin >> x;

  vector<int> v(n);
  for(int i = 0; i <n;i++) fin >> v[i];

   sort(v.begin(),v.end());

  int minutes = 0;
  int m;
  for(int i = 0; i < n; i++){

    if(i!=n-1){
      m = v[i]+v[i+1];
    }else{
      m = v[i];
    }

    if(m <= x){

      i++;
      minutes++;
    }else{
      minutes++;
    }
  }

  fout << minutes;
}