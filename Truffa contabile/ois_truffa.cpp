#include <bits/stdc++.h>

using namespace std;

#define MAXN 100000

int sfangate(int N, int V[]){

  sort(V,V+N);

  int sum = 0;

  for(int i = 0;i<N;i++)sum+=V[i];

  if(sum>0)return 0;
  int count  = 0;
  for(int i = 0;i<N;i++){

    if(V[i] <0){

      sum-=2*V[i];
      count++;

      if(sum>=0)return count;
    
    }
  }

  return N;
}

int V[MAXN];

int main() {
    FILE *fr, *fw;
    int N, i;

    fr = fopen("input.txt", "r");
    fw = fopen("output.txt", "w");
    assert(1 == fscanf(fr, "%d", &N));
    for(i=0; i<N; i++)
        assert(1 == fscanf(fr, "%d", &V[i]));

    fprintf(fw, "%d\n", sfangate(N, V));
    fclose(fr);
    fclose(fw);
    return 0;
}