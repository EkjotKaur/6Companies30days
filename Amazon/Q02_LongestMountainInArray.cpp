class Solution {
public:
    int longestMountain(vector<int>& arr) {
     
        int h=1, a=1, b=0, n=arr.size(); 
        if(n<3) return 0;
        for(int i=1; i<n; i++)
        {
            a=1;
            b=0;
            
            if(arr[i-1] >= arr[i]) continue;

            for(; i<n-1 && arr[i-1] < arr[i]; a++, i++);
            
            if(a < 2) continue;
            
            for(; i<n && arr[i-1] > arr[i]; i++, b++);

            if(b < 1) continue;
            
            h=max(h, a+b);
            a=1, b=0;
            i--;
        }
        
        return h>2?h:0;
    }
};
