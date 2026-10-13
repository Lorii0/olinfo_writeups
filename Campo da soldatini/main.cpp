#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> v,int pos){

    v[pos]=1;

    int streak=0;
    int max=INT_MIN;

    for(int i= 0;i<v.size();i++){

        if(v[i]==0){
                if(streak>max)max=streak;
            streak=0;
        }else{
            streak++;
            if(i==v.size()-1){

                if(streak>max)max=streak;
            }

        }
    }
    return max;
}
int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f; fin >> f;

  for(int t=1;t<=f;t++){


    int n;
    fin>>n;

    vector<int>v(n);

    for(int i=0;i<n;i++)fin>>v[i];

    int max=INT_MIN;
    int sold;
    for(int i=0;i<n;i++){

        if(v[i]==0)
        {
            sold=solve(v,i);
            if(sold>max)max=sold;
        }

    }

    if(max==INT_MIN)max=n;


    fout << "Case #" << t << ": " << max<< endl;
  }



}
