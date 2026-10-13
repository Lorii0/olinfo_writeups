#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    long long m,l;
    int n;
    fin>>n>>m>>l;

    map<long long,int>events;
        events[0]=0;
    for(int i=0;i<n;i++){
        long long p;fin>>p;

        long long open=p-m;

        long long close=p+m+1;

        if(open>0)events[open]+=1;
        else events[0]+=1;

        if(close<=l)events[close]-=1;

    }

    int min= INT_MAX;
    int c=0;
    for (auto i:events){

        c+=i.second;

        if(c<min)
            min=c;

    }

    fout<<min;

}
