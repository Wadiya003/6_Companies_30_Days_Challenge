class Solution {
public:
    int trailingZeroes(int n) {
        if(n==0){
            return 0;
        }
        if(n<5){
            return 0;
        }
        int ans=0;
        while(n){
            n/=5;
            ans+=n;
        }
        return ans;
    }
};
//we need to care about 5, 5×5, 5×5×5, 5×5×5×5