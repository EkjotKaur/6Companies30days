class Solution {
    int m,n,c;
    void solve(vector<vector<int>>& grid,  queue<vector<int>>&Q, int i, int j, int time)
    {
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1) return ;
        grid[i][j]=2;
        Q.push({i, j, time+1});
        c--;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        queue<vector<int>>Q;
        
        n=grid.size(), m=grid[0].size(), c=0;
        int t=0;
       
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j]==2)
                {
                    Q.push({i,j,0});
                }
                else if(grid[i][j]==1) c++;
            }
        }
        
        while(!Q.empty())
        {
            int i=Q.front()[0];
            int j=Q.front()[1];
            int time = Q.front()[2];
            Q.pop();
            t=time;
            solve(grid, Q, i-1, j, time);
            solve(grid, Q, i, j-1, time);
            solve(grid, Q, i+1, j, time);
            solve(grid, Q, i, j+1, time);
           
        }
        
        if(c>0) return -1;
        return t;
    }
};
