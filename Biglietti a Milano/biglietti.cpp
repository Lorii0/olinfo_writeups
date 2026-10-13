#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

  int n;fin >> n;
  int m;fin >> m;

  int singolo;fin >>singolo;
  int carnet;fin >>carnet;

  int prezzo1 = singolo*m;

  int costo = 0;
  int rimanenti = n;
  
  if(prezzo1<carnet){
    costo = singolo*n;
  }else{

    while(rimanenti>0){
      if((rimanenti*singolo)<carnet){
        costo += rimanenti*singolo;
        rimanenti=0;
      }else{
        costo += carnet;
        rimanenti -=m;
      }
    }
  }

  fout<<costo;
  
  
}

