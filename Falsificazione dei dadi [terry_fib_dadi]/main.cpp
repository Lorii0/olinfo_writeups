#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int k,a,b,c,d;
    fin>>k>>a>>b>>c>>d;

    for(int i=0;i<k;i++){

        if(a>0){
            a--;
            d++;
        }else if(b>0){
            b--;
            d++;
        }else if(c>0){
            c--;
            d++;
        }else break;

    }

    int punt=a+b*2+c*3+d*4;

    fout << "Case #" << t << ": " << punt<< endl;
  }



}
