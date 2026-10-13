#include <bits/stdc++.h>

using namespace std;

string solve(int a,int b)
{
    int n=(-1+(int)sqrt(1+8*(a+b)))/2;

    if(n*(n+1)/2!=a+b)return "-1";

    string res="";

    for(int i=n;i>0;i--){

        if(a>b){
            a-=i;
            res="1"+res;
        }else{
            b-=i;
            res="2"+res;
        }
    }
    return res;
}

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int t;
  fin >> t;
  for (int f = 1; f <= t; f++) {
    int a,b;
    fin >>a>>b;

    string res=solve(a,b);

    if(res=="-1")res="IMPOSSIBILE";
    fout << "Case #" << f << ": " << res<< endl;
  }
}
