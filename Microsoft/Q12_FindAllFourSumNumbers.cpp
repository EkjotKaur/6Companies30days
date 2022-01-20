#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int K) {
        // Your code goes here
        int n=arr.size();
        sort(arr.begin(), arr.end());
        unordered_map<string,int>h;
        vector<vector<int>>A;
        for(int i=0; i<n; i++)
        {
            // if(arr[i]>K) continue;
            for(int j=i+1; j<n; j++)
            {
                // if(arr[i]+arr[j]>K) continue;
                int x = arr[i]+arr[j];
                int k=j+1, l=n-1;
                while(k<l&&k>=0 && l<n)
                {
                    if(x+arr[k]+arr[l]==K)
                    {
                        string s = to_string(arr[i])+"-"+to_string(arr[j])+"-"+to_string(arr[k])+"-"+to_string(arr[l]);
                        if(h.find(s)==h.end())
                        {
                            A.push_back({arr[i], arr[j], arr[k], arr[l]});
                            h[s]++;
                        }
                        k++;
                        l--;
                    }
                    else if(x+arr[k]+arr[l]>K)
                        l--;
                    else
                        k++;
                }
            }
        }
        
        return A;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends
