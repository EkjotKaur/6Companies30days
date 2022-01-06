// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int A[9][9], B[9][9], C[3][3][9];
        memset(A, 0, sizeof(A));
        memset(B, 0, sizeof(B));
        memset(C, 0, sizeof(C));
         
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                if(mat[i][j]<=0) continue;
            
                int n = mat[i][j]-1;
                
                if(A[i][n]==1) return 0;
                A[i][n]=1;
                
                if(B[j][n]==1) return 0;
                B[j][n]=1;
                
                if(C[i/3][j/3][n]==1) return 0;
                C[i/3][j/3][n]=1;
                
            }
        }
       

        return 1;
    
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
