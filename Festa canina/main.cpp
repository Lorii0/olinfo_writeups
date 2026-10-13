#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int n;
    fin>>n;

    vector<int>inv(n);
    for(int i=0;i<n;i++)fin>>inv[i];

    sort(inv.begin(), inv.end(), greater<int>());

    int sum=0;
    for(int i=0;i<n;i++){

        if(inv[i]<0)break;

        sum+=inv[i];
    }

    fout << "Case #" << t << ": " << sum << endl;
  }



}
