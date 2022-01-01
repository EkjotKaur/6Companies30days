#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string src)
{     
    string s="";
    int n=src.length(), c=1;
    char j=src[0];
    for(int i=1; i<n; i++)
    {
        if(src[i]==j)
            c++;
        else
        {
            s+=j+to_string(c);
            c=1;
            j=src[i];
        }
    }
    if(c>0) s+=j+to_string(c);
    
    return s;
}     
 
