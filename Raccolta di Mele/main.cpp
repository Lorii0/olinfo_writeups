#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int n,m,c;
    fin>>n>>m>>c;

    int mele =0;
    for(int i=0;i<n;i++){

        if(mele+m>c){
            mele=c;
            break;
        }

        mele+=m;
    }



    fout << "Case #" << t << ": " << mele<< endl;
  }



}
