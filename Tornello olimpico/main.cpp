#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int n;fin>>n;

    int res=0;
    int dentro=0;
    int fuori=0;
    for(int i=0;i<n;i++){

        int c;fin>>c;

        if(c==1){
            if(fuori>0){
                fuori --;
                dentro++;
            }else{
                dentro++;
                res++;
            }
        }else{

             if(dentro>0){
                dentro --;
                fuori++;
            }else{
                fuori++;
                res++;

        }

    }



    }
    fout << "Case #" << t << ": " << res<<endl;
  }



}
