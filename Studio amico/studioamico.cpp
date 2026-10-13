#include <bits/stdc++.h>

using namespace std;

bool associabili(int N, int voti2[],int voti5[]){
    vector<int> v2(N),v5(N);
    for(int i=0;i<N;i++){
        v2[i]=voti2[i];
        v5[i]=voti5[i];
    }
    sort(v2.begin(),v2.end());
    sort(v5.begin(),v5.end());

    for(int i=0;i<N;i++){ 
        if(v2[i]>=v5[i])return false;
    }

    return true;

}