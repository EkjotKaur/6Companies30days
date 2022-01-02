
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here 
        int n=S.length();
        string s="";
      
        int c=1,d=0;
        if(S[0]=='I') d=1; else d=-1;
        
        for(int i=1; i<n; i++)
        {
            if(S[i]==S[i-1])
                c++;
            else
            {
                s+=to_string(c);
                d*=-1;
                c=1;
            }
            
        }
        s+=to_string(c);
           
        int j=1,k=n+1,i=0;
        string t="";
        bool z=0;
        
        if(S[0]=='D') 
        {
            int x = s[0]-'0', y=1;
            t+=to_string(j+x);
            j+=x;
            while(y<=x)
            {
                t+=to_string(j-y);
                y++;
            }
            j++;
            i++;
            z=1;
        }
        
        
        for(; i<s.length()-1; i+=2)
        {
            int x = s[i]-'0';
            if(!z) {x++; z=1;}
     
            while(x>1)
            {
                t+=to_string(j);
                j++;x--;
            }
            x = s[i+1]-'0';
 
            int y=1;
            t+=to_string(j+x);
            j+=x;
            while(y<=x)
            {
                t+=to_string(j-y);
                y++;
            }
            j++;
            
        }
        while(j<=n+1)
        {
            t+=to_string(j);
            j++;
        }
        
        
        return t;

    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends
