#include <bits/stdc++.h>

using namespace std;

int main(){
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  

  int t;fin >>t;
  for(int f=1;f<=t;f++){
    int n,m,q;fin>>n>>m>>q;
    string str;fin >> str;
    vector<string> v(m);

    string res="";

    v[0]=str;

    for(int i=0;i<q;i++){
      char c;fin >> c;
      int a,b;fin>>a>>b;

      if(c=='s'){
        string temp = v[a];

        v[b]+=temp[temp.length()-1];
        temp.pop_back();
        v[a]=temp;
      }else{
        string temp = v[a];
        res+=temp[b];
      }
    }

    fout << "Case #" << f << ": " << res << endl;

    
  }

}

