#include <bits/stdc++.h>

using namespace std;

int main() {
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n1;
  fin >> n1;


  int n2;
  fin >> n2;


  vector <int> v1(n1);

  for(int i = 0; i < n1; i++) fin >> v1[i];

  vector <int> v2(n2);

  for(int i = 0; i < n2; i++) fin >> v2[i];

  sort(v2.begin(), v2.end());

  int sum = 0;
  
  for(int i = 0; i < n1; i++){

    int x = v1[i];
    int dx = n2-1;

    int sx = 0;

    while(sx <= dx){

      int mid = (sx + dx)/2;
        if (x == v2[mid]){
            sum++;
            break;
        }
        else if (x > v2[mid])
            sx = mid + 1;
        else                     
            dx = mid - 1;
    }
  }

  fout << sum;

  
}




