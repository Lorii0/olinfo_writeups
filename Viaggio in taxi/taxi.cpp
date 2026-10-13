#include <stdio.h>
#include <assert.h>

#define MAXN 10000

int viaggia(int N, int C[]) {
    int res=0;
    int min=100001; 

    for(int i=0;i<N;i++){ 
        if(C[i]<min)min=C[i];
        res+=min;
        min++;
    }
    return res;
}


int C[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &C[i]));

    fprintf(fw, "%d\n", viaggia(N, C));
    fclose(fr);
    fclose(fw);
    return 0;
}
