#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int t;
  fin >> t;

  for(int j = 0; j < t; j++){
    
    int c;
    fin >> c;

    int f;
    fin >> f;

    int s;
    fin >> s;

    int films = 0;
    int songs = 0;
    int cap = 0;

    while(cap +f<= c){

      cap += f;
      films++;
    }

    while(cap +s <= c){
      cap += s;
      songs++;
    }

    
    fout << "Case #"<<j+1<<": "<<films<<" "<<songs<<endl;
  }

  
}


