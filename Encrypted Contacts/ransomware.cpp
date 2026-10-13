#include <bits/stdc++.h>

using namespace std;

int main(){
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;fin >> n;

  queue<string>q;
  for(int i=0;i<n;i++){
    string temp;
    fin>>temp;

    q.push(temp);
  }
  map<string,int>valori;

  for(int i=0;i<10;i++){
    string p;
    fin>>p;
    valori[p]=i;
  }

  for(int k=0;k<n;k++){
    string res="";
    string num ="";
    string current = q.front();
    q.pop();
    
    for(int i=0;i<current.size();i++){

      res+=current[i];

      if(valori.find(res)!=valori.end()){

        num+=to_string(valori[res]);
        res="";
      }
    }

    fout<<num<<endl;
  }
}