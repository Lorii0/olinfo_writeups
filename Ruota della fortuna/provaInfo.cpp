#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int t;
  fin >> t;

  for(int j = 0; j < t; j++){

    int n;
    fin>>n;

    vector<int> prize(n);
    vector<int> person(n);

    for(int i = 0; i < n; i++)fin >> prize[i];
    for(int i = 0; i < n; i++)fin >> person[i];

    int x;
    int min = INT_MAX;

    for(int i = 0; i < n; i++){

      x = 0;
      for(int k = 0; k < n; k++){
        x+=prize[k]*person[k];
      }

      if(x < min)min = x;

      int aux = prize[n-1];
      for(int k = n-1; k >0; k--){

        prize[k] = prize[k-1];
      }

      prize[0] = aux;
    }

    

    fout << "Case #"<<j+1<<": "<<min<<endl;
  }


}


