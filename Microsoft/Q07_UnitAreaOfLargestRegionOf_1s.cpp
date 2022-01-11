#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    bool check(int i, int j, int n , int m, vector<vector<int>>& grid)
    {
        if(i>=n || i<0 || j<0 || j>=m || grid[i][j]==0) return 0;
        return 1;
    }
    
    void pushInGraph(int i, int j, int i1, int j1, int m, vector<vector<int>>&G)
    {
        // cout<<(i-1)*m+j<<" "<<(i1-1)*m+j1<<"  ";
        G[(i)*m+j].push_back((i1)*m+j1);
    }
    
    int dfs(vector<vector<int>>&G, vector<int>&V, int i)
    {
        V[i]=1;
        int ans=0;
        for(int j=0; j<G[i].size(); j++)
            if(V[G[i][j]]==0) ans+=dfs(G, V, G[i][j]);
        return ans+1;
    }

    public:
    //Function to find unit area of the largest region of 1s.
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>>G(n*m);
        vector<int>g;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==0) continue;
                if(check(i-1, j, n, m, grid)) 
                    pushInGraph(i, j, i-1, j, m, G);
                if(check(i+1, j, n, m, grid)) 
                     pushInGraph(i, j, i+1, j, m, G);
                if(check(i, j-1, n, m, grid)) 
                     pushInGraph(i, j, i, j-1, m, G);
                if(check(i, j+1, n, m, grid)) 
                     pushInGraph(i, j, i, j+1, m, G);
                if(check(i-1, j+1, n, m, grid)) 
                     pushInGraph(i, j, i-1, j+1, m, G);
                if(check(i+1, j-1, n, m, grid)) 
                     pushInGraph(i, j, i+1, j-1, m, G);
                if(check(i-1, j-1, n, m, grid)) 
                     pushInGraph(i, j, i-1, j-1, m, G);
                if(check(i+1, j+1, n, m, grid)) 
                     pushInGraph(i, j, i+1, j+1, m, G);
                
                //  cout<<G[(i)*m+j].size()<<" "<<i<<" "<<j<<"  ";
                 g.push_back((i)*m+j);
            }
            // cout<<"\n";
           
        }
        
        vector<int>V(n*m);
        int ans=0;
        for(int i=0; i<g.size(); i++)
        {
            if(V[g[i]]==0)
            {
                // cout<<g[i]<<" ";
                ans=max(ans, dfs(G, V, g[i])); 
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
