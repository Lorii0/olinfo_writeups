#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int t;
  fin >> t;

  for(int j = 0; j < t; j++){

    int n1,n2,n3,n4;
    fin >> n1>>n2>>n3>>n4;

    int v;
    fin>>v;

    string str1,str2,str3,str4;

    fin >>str1>>str2>>str3>>str4;

    string virus;
    int ris1,ris2,ris3,ris4;
    for(int i = 0; i < n1-v+1; i++){

      virus = str1.substr(i,v);

      if(str2.find(virus) !=-1){
        if(str3.find(virus) !=-1){
          if(str4.find(virus) !=-1){

            ris1 = i;
            ris2 = str2.find(virus);
            ris3 = str3.find(virus);
            ris4 = str4.find(virus);
            break;
          }
        }
      }
    }

    fout << "Case #"<<j+1<<": "<<ris1<<" "<<ris2<<" "<<ris3<<" "<<ris4<<endl;
  }


}


