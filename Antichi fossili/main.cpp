#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int a,a1,b,b1,c,c1;
    fin>>a>>a1>>b>>b1>>c>>c1;

    int s=max(a,b);
    s=max(s,c);
    int f=min(a1,b1);
    f=min(f,c1);
    fout << "Case #" << t << ": " << f-s << endl;
  }



}
