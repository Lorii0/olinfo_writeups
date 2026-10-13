#include <bits/stdc++.h>

using namespace std;


vector<int>segTree;
int n;
int trueS;
void cambia( int x, int h){

    segTree[n + x] = h;

    for(int i = (n + x) / 2; i >= 1; i/=2){
        segTree[i] = max(segTree[i*2],segTree[i*2+1]);
    }

    return;
}

void inizializza(int N,vector<int>H){

    trueS=N;
    int i;
    for(i = 1; i < N;){
        i <<= 1;
    }
    N = i;
    H.resize(N);

    segTree.resize(2 * N);
    n = N;

    for(int i = 0; i < N; i++) {
        segTree[N + i] = H[i];
    }

    for(int i = N - 1; i >= 1; i--){
        segTree[i] = max(segTree[2*i], segTree[2*i + 1]);
    }

    return;
    
}

int RicercaDestra(pair<int,int>query_range, pair<int,int> node_range,int pos, int x){

    if(node_range.first>query_range.second||node_range.second<query_range.first)return -1;
    if(segTree[pos]<=x)return -1;
    if(node_range.second==node_range.first)return node_range.second;

    int medio=(node_range.second+node_range.first)/2;

    int res=RicercaDestra(query_range,{node_range.first,medio},pos*2,x);

    if(res==-1)res=RicercaDestra(query_range,{medio+1,node_range.second},pos*2+1,x);

    return res;
}

int RicercaSinistra(pair<int,int>query_range, pair<int,int> node_range,int pos, int x){



    if(node_range.first>query_range.second||node_range.second<query_range.first)return -1;
    if(segTree[pos]<=x)return -1;
    if(node_range.second==node_range.first)return node_range.first;

    int medio=(node_range.second+node_range.first)/2;

    int res=RicercaSinistra(query_range,{medio+1, node_range.second},pos*2+1,x);

    if(res==-1)res=RicercaSinistra(query_range,{node_range.first,medio},pos*2,x);

    return res;
}

pair<int, int> chiedi(int x){


    pair<int,int>res;   
    res.first=RicercaSinistra({0,x},{0,n-1},1,segTree[n+x]);

    if(res.first==-1)res.first=0;

    res.second=RicercaDestra({x, n-1},{0,n-1},1,segTree[n+x]);

    if(res.second==-1)res.second=trueS-1;
        return res;

}
