#include <bits/stdc++.h>

using namespace std;

bool poss( vector<int>ruota,int sz)
{
    for(int i=sz;i<ruota.size();i++){
        if(ruota[i]!=ruota[i-sz])return false;
    }


    return true;

}

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int t;
  fin >> t;
  for (int f = 1; f <= t; f++) {
    int n;
    fin >>n;

    vector<int>v(n);
    for(int i = 0; i < n; i++)fin >>v[i];

    int res=0;
    for(int i=1;i<=n;i++){

        if(n%i==0){

            bool p=poss(v,i);
            if(p)res+=n/i;
            if(p && i==1)break;
            while(p&& n%i==0)n/=i;
        }
    }


    fout << "Case #" << f << ": " << res<< endl;
  }
}
