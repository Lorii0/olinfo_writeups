#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  string str;
  int n;
  fin >> str >> n;

  unordered_map<string, int> m;

  for (int i = 0; i < n; i++) {
    string s;
    fin >> s;
    m[s] = 1;
  }

  if (m[str] != 1) {
    fout << str;
    return 0;
  }

  string res;
  for (int i = 1;; i++) {
    res = str + to_string(i);
    if (m[res] != 1) {
      fout << res;
      break;
    }
  }
}
