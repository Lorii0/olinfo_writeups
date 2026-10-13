#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int x, y;
  fin >> x >> y;

  vector<vector<int>> v(x, vector<int>(y));

  vector<vector<bool>> visited(x, vector<bool>(y, false));
  queue<pair<int, int>> q;
  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      fin >> v[i][j];
    }
  }

  int count = 0;

  for (int i = 0; i < x; i++) {
    for (int j = 0; j < y; j++) {
      if (v[i][j] == 1 && !visited[i][j]) {
        bool ok =true;
        
        if(i==0||j==0||i==x-1||j==y-1){
          ok=false;
        }
        q.push({i, j});

        while(!q.empty()){
          pair<int, int> p = q.front();
          q.pop();
          visited[p.first][p.second] =  true;

          //sinistra-----------------------------------------------------------
          
          if (p.second-1>= 0 && p.second -1< y){
            if(v[p.first][p.second-1] == 1 && !visited[p.first][p.second-1]){  
              
              if(p.first==0||p.second-1==0||p.first==x-1||p.second-1==y-1){
                ok = false;
              }
              q.push({p.first, p.second-1});
              
              
              visited[p.first][p.second-1] = true;

              
            }
          }

          //destra-----------------------------------------------------------
          
          if (p.second+1>= 0 && p.second +1< y){
            if(v[p.first][p.second+1] == 1 && !visited[p.first][p.second+1]){  

              if(p.first==0||p.second+1==0||p.first==x-1||p.second+1==y-1){
                ok = false;
              }
              q.push({p.first, p.second+1});
              
             
              visited[p.first][p.second+1] = true;


            }
          }

          //sotto-----------------------------------------------------------

          if (p.first+1>= 0 && p.first +1< x){
            if(v[p.first+1][p.second] == 1 && !visited[p.first+1][p.second]){  

              if(p.first+1==0||p.second==0||p.first+1==x-1||p.second==y-1){
                ok = false;
              }
              q.push({p.first+1, p.second});
              
              
              visited[p.first+1][p.second] = true;


            }
          }
          
          //sopra-----------------------------------------------------------


          if (p.first-1>= 0 && p.first-1< x){
            if(v[p.first-1][p.second] == 1 && !visited[p.first-1][p.second]){  

              if(p.first-1==0||p.second==0||p.first-1==x-1||p.second==y-1){
                ok = false;
              }
              q.push({p.first-1, p.second});
              
              
              visited[p.first-1][p.second] = true;


            }
          }  
        }

        if(ok==true){
          count++;
        }
       
        
      }
    }

    
  }
  fout<<count;
}