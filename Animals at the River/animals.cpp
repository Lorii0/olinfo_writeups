#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n;
  int s = 0;
  int prize;

  fin >> n;

  vector <int> sizes(n);

  vector <bool> in(n, true);

  for (int i = 0; i < n; i++) fin >> sizes[i];

  int animals = 0;
  for(int i = 0; i < n; i++){

    animals++;
    for(int j = i-1; j>=0; j--){

      if(sizes[i] > sizes[j] &&in[j]==true) {
        animals--;
        in[j] = false;
      }
    }
  }

  fout << animals;

  
}



