#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    int m;
    int solve(int arr[], int n, int i, int sum, vector<vector<int>>&dp)
    {
        if(i>=n || sum==0) return 0;
        if(dp[i][sum]!=-1) return dp[i][sum];
        int ans=0;
        if(arr[i]<=sum)
            ans=max(arr[i]+solve(arr, n, i+1, sum-arr[i], dp),solve(arr, n, i+1, sum, dp));
        else
            ans = solve(arr, n, i+1, sum, dp);
        dp[i][sum]=ans;
        return ans;
    }

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here

	    int sum=0;
	    for(int i=0; i<n; i++)
	        sum+=arr[i];
	    vector<vector<int>>dp(n+1, vector<int>(sum/2+1, -1));
	    return abs(sum - 2*solve(arr, n, 0, sum/2, dp));
	} 
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends
