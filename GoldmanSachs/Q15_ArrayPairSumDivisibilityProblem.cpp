#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int>h;
        for(auto c:nums)
        {
            h[c%k]++;
        }
        
        for(int i=1; i<(k+1)/2; i++)
        {
            if((h[i] || h[k-i]) && h[k-i]!=h[i])
                return 0;
        }
        
        if(h[0] && h[0]&1) return 0;
        if(k%2==0 && h[k/2] && h[k/2]&1) return 0;

        return 1;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends
