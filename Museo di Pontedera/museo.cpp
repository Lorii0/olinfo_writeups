#include <bits/stdc++.h>
using namespace std;


vector<int> segtree;
int Ng;


void init(int idx, vector<int>& v, int a, int b) {
    
    if (a == b) {
        segtree[idx] = v[a];
        return;
    }


    int centro = (a + b) / 2;
    int n1 = idx + idx;
    int n2 = n1 + 1;

    init(n1, v, a, centro);
    init(n2, v, centro + 1, b);


    if (segtree[n2] < segtree[n1]) {
        segtree[idx] = segtree[n1];
    } else {
        segtree[idx] = segtree[n2];
    }

}



void update(int a, int b, int p, int val, int n_curr) {
    
    if (a == b) {
        segtree[n_curr] = val;
        return;
    }

    int mid = (a + b) / 2;
    int left = n_curr * 2;
    int right = left + 1;


    if (p > mid) {
        update(mid + 1, b, p, val, right);
    } 
    else {
        update(a, mid, p, val, left);
    }


    int v_sx = segtree[left];
    int v_dx = segtree[right];

    if (v_sx < v_dx) segtree[n_curr] = v_dx;
    else segtree[n_curr] = v_sx;

}


int calcmax(int node, int r1, int r2, int i, int j) {
    
    if (i > r2) return 0;
    if (j < r1) return 0;


    if (i <= r1) {
        if (r2 <= j) {
            return segtree[node];
        }
    }


    int m = (r1 + r2) / 2;
    int figlio1 = node * 2;
    int figlio2 = node * 2 + 1;

    int res1 = calcmax(figlio1, r1, m, i, j);
    
    int res2 = calcmax(figlio2, m + 1, r2, i, j);


    if (res1 < res2) return res2;
    return res1;

}


void inizia(int N, vector<int> A) {
    
    Ng = N;
    segtree.assign(N * 4, 0);
    
    init(1, A, 0, N - 1);
}


void aggiorna(int P, int X) {
    
    update(0, Ng - 1, P, X, 1);

}


int massimo(int L, int R) {
    
    int risposta = calcmax(1, 0, Ng - 1, L, R);
    return risposta;

}