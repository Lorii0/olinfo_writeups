#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin("input.txt");
  ofstream fout("output.txt");

  int n;
  fin >> n;

  if (n == 1) {
    fout << -1;
    return 0;
  }

  if (n == 2) {
    fout << "15";
    return 0;
  }

  if (n == 3) {
    fout << "555";
    return 0;
  }

  if ((n % 2) == 0) {
    string str = "";
    for (int i = 0; i < n / 2; i++) {
      str += "15";
    }
    fout << str;
  } else {
    string str = "111";

    for (int i = 1; i < (n-1)/ 2 ; i++) {
      str += "15";
    }
    fout << str;
  }
}