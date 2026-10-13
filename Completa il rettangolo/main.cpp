#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int t;
  int n;
  fin >> t;
  for (int f = 1; f <= t; f++) {

    int x1,y1;
    fin>>x1>>y1;

    int x2,y2;
    fin>>x2>>y2;
    int x3,y3;
    fin>>x3>>y3;

    int x,y;

    if(x1==x2)x=x3;
    else if(x1==x3)x=x2;
    else x=x1;

    if(y1==y2)y=y3;
    else if(y1==y3)y=y2;
    else y=y1;


    fout << "Case #" << f << ": " << x<<" "<< y << endl;
  }
}
