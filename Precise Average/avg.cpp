#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  long long n, k;
  fin >> n >> k;

  long long avg = n * k;

  vector<int> v(n);

  long long sum = 0;

  for (int i = 0; i < n; i++) {
    fin >> v[i];
    sum += v[i];
  }

  if (avg == sum) {
    fout << 0;
  } else if (sum < avg) {
    fout << 1;
  } else {
    sort(v.begin(), v.end(), greater<int>());

    for (int i = 0;; i++) {

      sum-=v[i]-1;

      if(sum<=avg){
        fout<<i+1;
        return 0;
      }

      if(sum<0){
        fout<<-1;
        return 0;
      }


    }
  }
}