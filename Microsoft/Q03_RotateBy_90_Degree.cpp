//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
void rotate (vector<vector<int> >& matrix);


 // } Driver Code Ends
//User function template for C++

/* matrix : given input matrix, you are require 
 to change it in place without using extra space */
void rotate(vector<vector<int> >& matrix)
{
    // Your code goes here
    int n=matrix.size(), m=matrix[0].size();
    vector<vector<int> >M(n, vector<int>(n));
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(M[i][j]==0)
            {
                int x = matrix[i][j];
                int k=i, l=j;
                for(int s=0; s<3; s++)
                {
                    int a = l, b = n-1-k;
                    matrix[k][l]=matrix[a][b];
                    M[k][l]=1;
                    k=a,l=b;
                }
                matrix[k][l]=x;
                M[k][l]=1;
            }
        }
    }
}


// { Driver Code Starts.

int main()
{
    int t;
    cin>>t; 
    while(t--)
    {
        int n;
        cin>>n; 
        vector<vector<int> > matrix(n);
        for(int i=0; i<n; i++)
        {
            matrix[i].resize(n);
            for(int j=0; j<n; j++)
                cin>>matrix[i][j]; 
        }
        rotate(matrix);
        for (int i = 0; i < n; ++i)
        {
            for(int j=0; j<n; j++)
                cout<<matrix[i][j]<<" ";
            cout<<"\n";
        }
    }
    return 0;
}

  // } Driver Code Ends
