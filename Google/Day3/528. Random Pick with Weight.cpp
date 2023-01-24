class Solution {
public:vector<int>arr;
    Solution(vector<int>& w) {
        arr.push_back(w[0]);
        for(int i=1;i<w.size();i++){
            arr.push_back(arr[i-1]+w[i]);//prefix sum
        }
    }
    
    int pickIndex() {
        int n= rand()%arr.back()+1;
        auto it=lower_bound(arr.begin(),arr.end(),n);
        return it-arr.begin();

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */