#include <bits/stdc++.h>

using namespace std;
int main() {
  
  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  int time1 = 0;
  
  int time2 = 0;

  fin >> n;
  vector <int> array(n);
   vector <int> array2(n);

  

  for(int i = 0; i<n; i++) fin >> array[i];

  for(int i = 0; i<n; i++) fin >> array2[i];

  for(int i = 0; i<n; i++){

    time1 += array[i];
    time2 += array2[i];
  }
  int min1 = array[0];
  int min2 = array2[0];

  for(int i = 0; i<n; i++){

    if(array[i] < min1) min1 = array[i];
    if(array2[i] < min2) min2 = array2[i];
  }

  if(time1 < time2) fout << "Hamilton";
  if(time2 < time1) fout << "Verstappen";

  if(min1 < min2) fout << "\nHamilton";
  if(min2 < min1) fout << "\nVerstappen";
  
  
}