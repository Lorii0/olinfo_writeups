#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int t;
  fin >> t;

  for(int j = 0; j < t; j++){
    int n;
    fin >> n;

    int k;
    fin >> k;

    int eggs = n;
    int lab = 0;
    int p;
    while(eggs > 0){

      p = eggs;
      int aux = eggs;

      
      eggs+= aux/k;

      eggs-=p;

      lab+=p;
    }

    fout << "Case #"<<j+1<<": "<<lab<<endl;
  }

  
}

