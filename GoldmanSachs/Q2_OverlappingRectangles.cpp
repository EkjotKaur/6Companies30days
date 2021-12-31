// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
    bool func(int L1[], int R1[])
    {
        return L1[1]<R1[1] || L1[0]>R1[0] ? 0 : 1;
    }
  public:
    int doOverlap(int L1[], int R1[], int L2[], int R2[]) {
        
        if(!func(L1,R1))  return 0;
        if(!func(L2,R2))  return 0;

        if(((L1[0]<=L2[0] && L2[0]<=R1[0]) || (L2[0]<=L1[0] && L1[0]<=R2[0])) && ((R1[1]<=R2[1] && R2[1]<=L1[1]) || (R2[1]<=R1[1] && R1[1]<=L2[1])))
            return 1;

        return 0;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int p[2], q[2], r[2], s[2];
        cin >> p[0] >> p[1] >> q[0] >> q[1] >> r[0] >> r[1] >> s[0] >> s[1];
        Solution ob;
        int ans = ob.doOverlap(p, q, r, s);
        cout << ans << "\n";
    }
}  // } Driver Code Ends
