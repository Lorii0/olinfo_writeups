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

    vector<int> squads(n);

    for(int i = 0; i < n; i++)fin >> squads[i];

    int candy = 0;

    int ok = false;

    while(ok == false){

      candy++;
      ok = true;
      for(int i = 0; i < n; i++){

        if(candy % squads[i] != 0){
          ok = false;
          break;
        }
      }
    }


    fout << "Case #"<<j+1<<": "<<candy<<endl;
  }


}


