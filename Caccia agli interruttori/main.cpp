#include <bits/stdc++.h>

using namespace std;


pair<int,int> bfs(const vector<vector<int>>& g, vector<int> sources)
{
	vector<int> dist(g.size(), INT_MAX);
	vector<bool> vis(g.size(), false);
	queue<pair<int, int>> q;

	for(int i=0;i<sources.size();i++)q.push({0, sources[i]});


	while (!q.empty())
	{
		auto [d, x] = q.front();
		q.pop();

		if (vis[x])
			continue;
		vis[x] = true;
		dist[x] = d;

		for (auto c : g[x])
			q.push({ d + 1, c });
	}

	int max=INT_MIN;
	int maxI=0;
	for(int i=0;i<dist.size();i++)
    {
        if(dist[i]>max){
            max=dist[i];
            maxI=i;
        }
    }

    max++;
    return {maxI,max};
}


int main(){
  ifstream fin("input.txt");
  ofstream fout("output.txt");

    int t;fin>>t;

    for(int f=1;f<=t;f++){

        int n;fin>>n;
        int a;fin>>a;
        int b;fin>>b;

        vector<int> sources(a);

        for(int i=0;i<a;i++){
            fin >>sources[i];
        }
         vector<vector<int>> g(n);
         for(int i=0;i<b;i++){
            int n1;int n2;
            fin>>n1>>n2;
            g[n1].push_back(n2);
            g[n2].push_back(n1);
         }

         pair<int,int> res=bfs(g,sources);

        fout << "Case #" << f << ": " << res.first << " " << res.second << "\n";
    }

    return 0;

}
