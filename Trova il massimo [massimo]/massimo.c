
#include <stdio.h>

int trova_massimo(int N, int V[]){ 
    int i,max;
    max=V[0];
    for(i=0;i<N;i++){
    if(V[i]>max){
    max=V[i];
    }
}
return max;
}