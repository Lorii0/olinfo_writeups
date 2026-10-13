#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int t;
  fin >> t;

  vector<int> points{25,18,15,12,10,8,6,4,2,1,0,0,0,0,0,0,0,0,0,0};
  for(int i = 0; i < t; i++){

    int n; fin >> n;

    int score = 0;
    int opp = 0;
    for(int k = 0;k<n;k++){

      int a;fin >> a;

      if(a == 1){

        score += points[0];
        opp += points[1];
      }else{

        opp+= points[0];
        score += points[a-1];
      }

    }

    if(score >= opp) fout << "Champion" << endl;
    else fout << "Practice harder" << endl;
  }


}