// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    int MCM(int p[], int i, int j, vector<vector<int>>&A, vector<vector<string>>&B)
    {
        if(i>=j) return 0;
        if(A[i][j]!=-1) return A[i][j];
        
        int ans = INT_MAX;
        for(int k=i; k<j; k++)
        {
            int y = MCM(p, i, k, A, B) + MCM(p, k+1, j, A, B) + p[i-1]*p[k]*p[j];
            if(y<ans)
            {
                ans = y;
                if(i==k && j==k+1)
                    B[i][j]="(XX)";
                else if(i==k)
                    B[i][j]="(X"+ B[i][k] + B[k+1][j] +")";
                else if(j==k+1)
                    B[i][j]="("+ B[i][k] + B[k+1][j] +"X)";  
                else
                    B[i][j]="("+ B[i][k] + B[k+1][j] +")";  
            }
        }
        
        A[i][j] = ans;
        return A[i][j];
    }
public:
    string matrixChainOrder(int p[], int n){
        // code here
        if(n==2) return "A";

        vector<vector<int>>A(n, vector<int>(n, -1));
        vector<vector<string>>B(n, vector<string>(n));
        
        MCM(p, 1, n-1, A, B);
        
        string s = B[1][n-1];
        
        char a='A';
        for(int i=0; i<s.length(); i++)
        {
            if(s[i]=='X')
                s[i]=a++;
        }
        
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
