#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> v(n);
    int cut = -1;
    bool ok=true;

    for(int i=0; i<n; i++){
        cin >> v[i];
    }

    for(int i = 1; i<n; i++){
        if(v[i] < v[i-1]){
            cut = i;
            break;
        }
    }

    if(cut == -1){
        cout << 0 << endl;
        return 0;
    }

    if(v[n-1] > v[0]) {
        ok = false;
    }

    for(int i = cut; i<n-1; i++){
        if(v[i] > v[i+1]){
            ok = false;
            break;
        }
    }

    

    if(ok){
        cout << n - cut << endl;
    } else {
        cout << -1 << endl;
    }

}