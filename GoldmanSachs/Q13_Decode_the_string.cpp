// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here

        string t="";
        int j=0,n=s.length();
        while(j<n)
        {
            if(s[j]>'9' || s[j]<'0')
            {
                t+=s[j];
                j++;
                continue;
            }
            int x=0;
            while(s[j]<='9' && s[j]>='0')
            {
                x=x*10+s[j]-'0';
                j++;
            }
            int l=1;
            j++;
            string y="";
            for(; j<n && l; j++)
            {
                if(s[j]=='[') l++;
                else if(s[j]==']') l--;
                if(!l) break;
                y+=s[j];   
            }
            while(x--)
                t+=decodedString(y);
            j++;
        }
        
        return t;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
