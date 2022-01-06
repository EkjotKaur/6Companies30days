
 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    queue<char>Q;
		    unordered_map<char,int>h;
		    int n=A.length();
		    
		    string ans="";
		    for(int i=0; i<n; i++)
		    {
		        if(h[A[i]]==0) 
		            Q.push(A[i]);
		        h[A[i]]++;
          
		        while(!Q.empty() && h[Q.front()]>1) Q.pop();
          
		        if(!Q.empty())
		            ans+=Q.front();
		        else
		            ans+="#";
		    }
		    
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
