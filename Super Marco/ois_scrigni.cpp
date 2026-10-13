#include <bits/stdc++.h>

using namespace std;

int main() {

  ifstream fin ("input.txt");
  ofstream fout ("output.txt");

	long long n;
	fin >> n;
	
	auto res=n*(n-1)/4.0;
	fout << res;
}