#include <bits/stdc++.h>

using namespace std;

set<long long> s;

void inizia(){

}

void apri(long long p){
    s.insert(p);
}

void chiudi(long long p){
  s.erase(p);
}

long long chiedi(long long p){
  if(s.size() == 0)
    return -1;
  set<long long>::iterator it_prec; 
  auto it = s.lower_bound(p);
  it_prec = prev(it);
  if(it == s.end()) return *it_prec;
  if(it != s.begin()){
    
      if (abs(*it - p) > abs(p - *it_prec))
          return *it_prec;
    else
      return *it;
    }
  else
    return *it;

}