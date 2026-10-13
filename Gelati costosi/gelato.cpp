#include <bits/stdc++.h>
using namespace std;

int presta(int N, int C, vector<int> P)
{
    vector<int>v=P;
    sort(v.begin(), v.end(),greater<int>());

    for(int i=0;i<N;i++){
        C-=v[i];
        if(C<=0)return i+1;
    }

    return -1;

}