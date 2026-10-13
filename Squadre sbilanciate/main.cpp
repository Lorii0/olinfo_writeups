#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int num = 0;


    int n;
    fin >> n;
    vector<int> sq1(n);
    map<int,int> sq2;



    for(int i=0;i<n;i++){
      fin >> sq1[i];
    }

    for(int i=0;i<n;i++){
      int s;
      fin>>s;
      sq2[s]+=1;
    }

    for(int i = 0;i<sq1.size();i++){

      int curr =sq1[i];

      if(sq2.find(curr)!=sq2.end()&&sq2[curr]>0){
        sq2[curr]-=1;
        num++;
      }

    }

    fout << "Case #" << t << ": " << num << endl;
  }



}
