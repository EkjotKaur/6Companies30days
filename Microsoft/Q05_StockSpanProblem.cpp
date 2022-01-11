#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int price[], int n)
    {
       // Your code here
       vector<int>A(n);
       A[0]=1;
       stack<pair<int,int>>S;
       S.push({price[0], 1});
       
       for(int i=1; i<n; i++)
       {
            
            int ans=1;
            while(!S.empty() && S.top().first<=price[i])
            {
                ans+=S.top().second;
                S.pop();
            }
            A[i]=ans;
            S.push({price[i], A[i]});
        
       }
       
       return A;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends
