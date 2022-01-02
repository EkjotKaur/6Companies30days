#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string strr){
		    // Code here
		    int n=strr.size();
		    vector<long long>A;
		    int zero=0;
		    string str="";
		    for(int i=0; i<n; i++)
		    {
		        if(i==0 && strr[i]=='0') return 0;
		        if(strr[i]=='0' && (strr[i-1]>'2' || strr[i-1]=='0')) return 0;
		        if(strr[i]=='0')
		            str[str.length()-1]='X';
		        else
		            str+=strr[i];
		    }
		    n=str.size();
		    A.push_back(1);
		    if(n==1) return 1;

		    if(str[1]!='X' && str[0]<'2' || (str[0]=='2' && str[1]<'7'))
		        A.push_back(2);
		    else A.push_back(1);
    
            int k=2;
            int y=1e9+7;
		    for(int i=2; i<n; i++)
		    {
		        if(str[i]!='X'&& str[i-1]<'2' || (str[i-1]=='2' && str[i]<'7') )
		          A.push_back((A[k-1]+A[k-2])%y);
		        else A.push_back(A[k-1]);
		        k++;
		    }
		    
		    int x = A[k-1]%y;
		    return x;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
