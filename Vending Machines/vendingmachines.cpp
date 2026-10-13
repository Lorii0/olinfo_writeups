#include <bits/stdc++.h>

using namespace std;

map<int,bool> grill;
int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int t; fin >> t;

  for(int i = 0; i < t; i++){

    int n; fin >> n;
    int q; fin >> q;

    int money = 0;

    vector<int> prizes(n);
    vector<int>trans(q);

    for(int j = 0; j < n; j++)fin >> prizes[j];
     for(int j = 0; j < q; j++)fin >> trans[j];

    bool hacked = false;

    for(int j = 0; j < q; j++){

      if(trans[j] > 0) money += trans[j];
      else{

        int idx = abs(trans[j]) - 1;

        money-= prizes[idx];
      }

      if(money < 0){
        hacked = true;
        break;
      }
    }

    if(hacked) fout << "HACKER" << endl;
    else fout <<"OK" << endl;
  }

  

}

