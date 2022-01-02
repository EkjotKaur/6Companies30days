
using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int r=0;
        vector<int>A(n+1);
        for(int i=0; i<n; i++)
        {
            A[arr[i]]++;
            if(A[arr[i]]>1) r=arr[i];
        }
      
        int *y = new int[2];
        y[0] = r;
        for(int i=1; i<=n; i++)
        {
            if(A[i]==0) r=i;
        }
        y[1] = r;
        return y;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends
