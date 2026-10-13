#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n;
  fin >> n;

  vector<int> v(n);

  for(int i = 0;i<n;i++) fin >> v[i];

    sort(v.begin(),v.end(),greater<int>());

  int sum = 0;

  int counter = 1;

  for(int i = 0;i<n;i++){

    if(counter == 3){

      counter = 1;
    }else{

      sum+=v[i];
      counter++;

      
    }
  }

  fout << sum;
}