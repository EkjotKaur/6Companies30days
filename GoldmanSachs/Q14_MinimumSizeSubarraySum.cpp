class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int x=INT_MAX;
        
        int y=0,j=0;
        for(int i=0; i<nums.size(); i++)
        {
            y+=nums[i];
            if(y>=target)
                x=min(x,i-j+1);

            for(;y>=target;)
            {
                y-=nums[j++];
                if(y>=target)
                    x=min(x,i-j+1);                
            }

        }
        
        return x==INT_MAX?0:x;
        
        
    }
};
