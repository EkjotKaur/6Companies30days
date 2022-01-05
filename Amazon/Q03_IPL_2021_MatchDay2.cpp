

 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        if(k==1) return arr;
        int x = n-k+1;
        unordered_map<int,int>h;
        priority_queue<int>P;
        vector<int>A(x);
      
        for(int i=0; i<k; i++)
        {
            A[0]=max(arr[i], A[0]);
            h[arr[i]]++;
            P.push(arr[i]);
        }
      
        for(int i=0; i<x-1; i++)
        {
            h[arr[i]]--;
            h[arr[i+k]]++;
            P.push(arr[i+k]);
            if(arr[i]<A[i])
                A[i+1]=max(arr[i+k], A[i]);
            else
            {
                while(h[P.top()]<1)
                {
                    P.pop();
                }
                A[i+1]=P.top();
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

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends
