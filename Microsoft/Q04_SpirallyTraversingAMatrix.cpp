#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        vector<int>A;
        for(int i=0; i<(r+1)/2 && i<(c+1)/2; i++)
        {
            int j=i;
            for(j=i; j<c-i; j++)
                A.push_back(matrix[i][j]);   
            if(j==i) break;
            j--;
            
            int k=i+1;
            for(k=i+1; k<r-i; k++)
                A.push_back(matrix[k][j]);  
            if(k==i+1) break;
            k--;
            
            int l=j-1;
            for(l=j-1; l>=i; l--)
                A.push_back(matrix[k][l]);
            if(l==j-1) break;
            l++;
            
            for(int s=k-1; s>i; s--)
                A.push_back(matrix[s][l]);
        }
        return A;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
