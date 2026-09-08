class Solution {
public:
    int countCommas(int n) {
        int count=0,i=0;
        if(n<1000)
        {
            count=0;
        }
        if(n>=1000)
        {
        for(i=1000;i<=n;i++)
        {
            count=count+1;
        }
        }

        return count; 
    }
};