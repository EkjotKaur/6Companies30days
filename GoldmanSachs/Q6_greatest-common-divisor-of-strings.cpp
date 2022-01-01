class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        string t="";
        string ans="";
        int n1=s1.length(), n2=s2.length();
        for(int i=0; i<n1 && i<n2; i++)
        {
            if(s1[i]==s2[i])
            {
                t+=s1[i];
                int n3=t.length();
                if(n1%n3==0 && n2%n3==0)
                {
                    string x="";
                    for(int j=0; j<n1/n3; j++)
                    {
                        x+=t;
                    }
                    if(x!=s1)
                        continue;
                    x="";
                    for(int j=0; j<n2/n3; j++)
                    {
                        x+=t;
                    }
                    if(x==s2)
                        ans=t;
                }
                
            }
            else
                return "";
        }
        
        return ans;
    }
};
