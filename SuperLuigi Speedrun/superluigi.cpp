#include <bits/stdc++.h>
using namespace std;

int solve(int n,int m,vector<int>h,vector<int>d){
    vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
    vector<vector<int>>heights(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            heights[i][j]= h[i] +d[i]*j;
            //cout << " i: "<<i<<" j: "<<j<<" height: "<<heights[i][j]<<"       ";
        }
        //cout << endl;
    }
    for(int i=0;i<m;i++){
        dp[0][i]= heights[0][i];
    }
    
    for(int i=1;i<n;i++){
        int up_idx=0;
        for(int j=0;j<m;j++){
            //cout << "up: "<<up<<" down: "<<down<< " i: "<<i<<" j: "<<j<< " curr height: " << heights[i][j]<<endl;
            while(heights[i-1][up_idx]<heights[i][j]){
                
                if(up_idx!=m-1)
                    up_idx++;
                else break;
            }
            //cout << "up: "<<heights[i-1][up_idx]<<" down: "<<heights[i-1][up_idx-1]<< " i: "<<i<<" j: "<<j<< " curr height: " << heights[i][j]<<endl;
            
            
            if(up_idx>0)dp[i][j]=min(dp[i-1][up_idx]+abs(heights[i-1][up_idx]-heights[i][j]),dp[i-1][up_idx -1]+abs(heights[i-1][up_idx-1]-heights[i][j]));
            else dp[i][j]= dp[i-1][up_idx]+abs(heights[i-1][up_idx]-heights[i][j]);
            //cout<<"res: --> "<<dp[i][j]<<"  <--- ";   
        }
        //cout << endl;
        
    }

    int ans=INT_MAX;
    for(int i=0;i<m;i++){
        ans=min(ans,dp[n-1][i]);
    }
    return ans;
}
int main(){
    ofstream cout("output.txt");
    int t;
    cin >> t;
    for(int caso=1; caso<=t; caso++){
        int n,m;
        cin >> n >> m;
        
        vector<int>h(n);
        vector<int>d(n);
        
        for(int i=0;i<n;i++){
            cin >> h[i];
        }
        for(int i=0;i<n;i++){
            cin >> d[i];
        }
        
        
        cout << "Case #"<<caso<<": "<<solve(n,m,h,d)<< endl;
    }
}