//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    vector<string>ans;
    void solve(int a[], int N, vector<string>&A, int i, string s)
    {
        if(i>=N) 
        {
            ans.push_back(s);
            return;
        }
        for(int j=0; j<A[a[i]].size(); j++)
        {
            string t=s;
            t+=A[a[i]][j];
            solve(a, N, A, i+1, t);
        }
    }
    public:
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N)
    {
        //Your code here
        char x='a';
        vector<string>A(10, "");
        for(int i=2; i<=9; i++)
        {
            int n=3;
            if(i==7 || i==9) n=4;
            for(int j=0; j<n; j++)
                A[i]+=x++;
        }
        
        solve(a, N, A, 0, "");
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends
