#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
	    vector<long long>A={1,2,3,4,5};
	    int i=2,j=2,k=1;
	    if(n<=5) 
	        return A[n-1];
	    int m=5;
	    n-=5;
	    while(n--)
	    {
	        A.push_back(min(2*A[i], min(3*A[j], 5*A[k])));
	        if(A[m]==2*A[i]) i++;
	        if(A[m]==3*A[j]) j++;
	        if(A[m]==5*A[k]) k++;
	        m++;
	        
	    }
	    
	    return A[m-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends
