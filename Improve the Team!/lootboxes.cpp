#include <bits/stdc++.h>

using namespace std;


int n;
int coins;

vector <pair<int,int>> v;
vector<vector<short>> memo(5001,vector<short>(10002,-1));

int solve(int pos,int soldi)
{  
  if(pos >= n) return 0;

  if(memo[pos][soldi] >= 0) return memo[pos][soldi];

  int res = 0;

  if(v[pos].second <= soldi){
    res = max(res,solve(pos+1,soldi-v[pos].second)+v[pos].first);
  }

  res = max(res,solve(pos+1,soldi));
  return memo[pos][soldi] = res;
}

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");
  
  fin >>n;
  fin >> coins;

  v.resize(n);

  for(int i = 0;i<v.size();i++){
    fin >> v[i].first;
    fin >> v[i].second;
  }

  fout << solve(0,coins);
}

