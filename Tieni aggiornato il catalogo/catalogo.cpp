#include <bits/stdc++.h>

using namespace std;

unordered_map<long long,int>cat;
void aggiungi(long long int id){
  cat[id]++;
}
void togli(long long int id){
  cat[id]--;
}
int conta(long long int id){
  return cat[id];
}
