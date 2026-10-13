#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int n;
    fin >> n;
    vector<int> balle(n);




    for(int i=0;i<n;i++){
      fin >> balle[i];
    }
    int ind=-1;
    int val=0;

    for(int i=1;i<n-1;i++){

        int p;

        if(balle[i]>balle[i-1]&&balle[i]>balle[i+1]){

            p=min(balle[i]-balle[i-1],balle[i]-balle[i+1]);
            if(p>val){
                val=p;
                ind=i;
            }
        }



    }
    fout << "Case #" << t << ": " << ind << endl;
  }



}
