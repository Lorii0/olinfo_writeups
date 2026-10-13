#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int n;
    fin>>n;

    vector<int>v1(n);
    vector<int>v2(n);

    for(int i=0;i<n;i++)fin>>v1[i];
    for(int i=0;i<n;i++)fin>>v2[i];

    int s=0;
    for(int i=0;i<n;i++){
        if(v1[i]!=v2[i])s++;
    }



    fout << "Case #" << t << ": " << s<< endl;
  }



}
