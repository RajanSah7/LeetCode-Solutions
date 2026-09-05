class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size(),i;
        vector<int> right(n);
        right[n-1]=nums[n-1];
        for(i=n-2;i>=0;i--)
        {
            right[i] = min(right[i+1],nums[i]);
        }
        int left_val=0;
        for(i=0;i<n;i++)
        {
            left_val = max(left_val,nums[i]);

            if(left_val-right[i]<=k)
            {
                return i;
            }
        }

        return -1;
    }
};