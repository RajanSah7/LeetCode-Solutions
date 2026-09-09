class Solution {
public:
    long long countCommas(long long n) {
        long count=0,i;
        if(n<1000)
        {
            count=0;
        }
        for(i=1000;i<=n;i*=1000)
        {
            count += n-i+1;
        }
        return count;
    }
};