#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int t;
  fin >> t;

  for(int k = 0; k < t; k++){
    int n;
    fin >> n;

    int sum = 0;
    for(int i = 0; i<n; i++){

      

      int a, b,c;

      fin>>a>>b>>c;

      int max = a;
      if(b>max) max = b;
      if(c>max) max = c;

      sum+=max;
    }

    fout << "Case #"<<k+1<<": "<<sum<<endl;
  }

  
}
