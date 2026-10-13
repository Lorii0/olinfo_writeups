#include <bits/stdc++.h>

using namespace std;

int n;

vector<vector<vector<int>>> memo(1005, vector<vector<int>>(3, vector<int>(3, -1)));

int solve(int pos, int l, int r,vector<int> lf,vector<int> rt) {
  if (pos >= n)
    return 0;

    if(memo[pos][l][r]!=-1)return memo[pos][l][r];



  int res = 2e9;

  if (l < 2)
    res = min(res, solve(pos + 1, l + 1, 0,lf,rt) + lf[pos]);

  if (r < 2) {
    res = min(res, solve(pos + 1, 0, r + 1,lf,rt) + rt[pos]);
  }

  memo[pos][l][r]=res;
  return res;
}

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int f;
  fin >> f;


  for (int t = 1; t <= f; t++) {

    fin >> n;

    vector<int> lf(n);
    vector<int> rt(n);

    for (int i = 0; i < n; i++) {
      fin >> lf[i] >> rt[i];
    }

    fout << "Case #" << t << ": " << solve(0, 0, 0,lf,rt) << endl;
    memo.assign(1005, vector<vector<int>>(3, vector<int>(3, -1)));
  }
}
