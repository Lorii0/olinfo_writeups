#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int n;fin>>n;

    vector<int>ossa(n);

    for(int i= 0;i<n;i++)fin>>ossa[i];

    int count=0;
    for(int i=0;i<n;i++)
    {
        while(ossa[i]>0){
                count++;
            ossa[i]--;
            int j=1;
            while(i+j<n&&ossa[i+j]>0){

                ossa[i+j]--;
                j++;
            }

        }
    }

    fout << "Case #" << t << ": " << count << endl;
  }



}
