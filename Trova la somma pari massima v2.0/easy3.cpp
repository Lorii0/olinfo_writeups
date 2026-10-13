#include <bits/stdc++.h>

using namespace std;
int main() {
  
    ifstream fin("input.txt");
      ofstream fout("output.txt");

        int n;
          fin >> n;

            vector<int> v (n);

              for(int i=0;i<n;i++){
                  fin>>v[i]; 
                    }

                    sort(v.begin(),v.end(),greater<int>());

                      int p1=-1,p2=-1,d1=-1,d2=-1;
                        for(int i=0;i<n;i++){
                            
                                if(v[i]%2==0){
                                      if(p1==-1){
                                              p1=v[i];
                                                    }else if(p2==-1){
                                                            p2=v[i];
                                                                  }else continue;
                                                                      }
                                                                          if(v[i]%2==1){
                                                                                if(d1==-1){
                                                                                        d1=v[i];
                                                                                              }else if(d2==-1){
                                                                                                      d2=v[i];
                                                                                                            }else continue;
                                                                                                                }
                                                                                                                  }

                                                                                                                    if(p1==-1||p2==-1){
                                                                                                                        if(d1==-1||d2==-1){
                                                                                                                              fout<<-1;
                                                                                                                                  }else fout<<d1+d2;
                                                                                                                                      
                                                                                                                                        }else if(d1==-1||d2==-1){
                                                                                                                                              if(p1==-1||p2==-1){
                                                                                                                                                      fout<<-1;
                                                                                                                                                            }else fout<<p1+p2;
                                                                                                                                                              }else fout<<max(p1+p2,d1+d2);

                                                                                                                                                                

                                                                                                                                                                  
                                                                                                                                                                      
                                                                                                                                                                      }