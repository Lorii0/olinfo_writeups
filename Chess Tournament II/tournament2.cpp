#include <bits/stdc++.h>

using namespace std;
int main() {
  
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int k;

  fin >> k;
    for(int j = 0; j < k; j++) {
      
      int mosse;
      int rating;
      int soglia;
      double sommaMosse = 0;

      

      fin >> mosse;
      fin >> rating;
      fin >> soglia;

      vector <int> array(mosse);

      for(int i = 0; i < mosse; i++) fin >> array[i];

      for(int i = 0; i < mosse; i++)sommaMosse += array[i];

        sommaMosse = sommaMosse / mosse;

        
        if(j == 0){
          if((sommaMosse - rating) > soglia) fout << "Cheater";
          else fout << "Innocent";
        }else{
          if((sommaMosse - rating) > soglia) fout << "\nCheater";
          else fout << "\nInnocent";
          
        }

    }
}

