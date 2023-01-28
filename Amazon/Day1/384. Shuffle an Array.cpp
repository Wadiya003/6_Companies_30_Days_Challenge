class Solution {
public:
vector<int>v;
int n;
// Fisher–Yates shuffle Algorithm works in O(n) time complexity. The assumption here is, we are given a function rand() that generates a random number in O(1) time. The idea is to start from the last element and swap it with a randomly selected element from the whole array (including the last). Now consider the array from 0 to n-2 (size reduced by 1), and repeat the process till we hit the first element. 
    Solution(vector<int>& nums) {
        v=nums;
        n=v.size();
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        vector<int>copy=v;
        int pointer=n;
        for(int i=n-1;i>=0;i--){
            int r=rand() % pointer;
            swap(copy[i],copy[r]);
            pointer--;
        }
        return copy;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */