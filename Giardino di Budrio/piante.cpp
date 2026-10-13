#include <bits/stdc++.h>

using namespace std;

int pollice_verde(int N, vector<int> H) {


    int c =0;
    for(int i= 0;i<N;i++){

        if(i==0){
            if(H[i]>=H[i+1])c++;
        }else if(i==N-1){
            if(H[i]>=H[i-1])c++;
        }else{
            if(H[i]>=H[i-1]&&H[i]>=H[i+1])c++;
        }

    }

    return c;
}
