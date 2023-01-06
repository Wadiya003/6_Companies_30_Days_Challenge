class Solution {
public:
  
 
   int gcd(int a, int b)
    {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }
    
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        // sort(numsDivide.begin(),numsDivide.end());
        int n = nums.size(), m = numsDivide.size();
        unordered_map<int,int> mp;
        for(auto j : nums)
            mp[j]++;
        int g = numsDivide[0];
        set<int> divisors;
        for (int i = 1; i < m; i++) {
            g = gcd(numsDivide[i], g);
        }
        for (int i = 1; i * i <= g; i++) {
            if (g % i == 0) {
                divisors.insert(i);
                if (g / i != i)
                    divisors.insert(g / i);
            }
        }
        vector<int> dd;
        bool flag = 0;
        for (auto& it : divisors)
            dd.push_back(it);
        sort(dd.begin(),dd.end());
        int ans = 0,ch = 0;
        for(int i = 0;i < dd.size();i++){
            if(mp.find(dd[i]) != mp.end()){
                flag = 1;
                ch = dd[i];
                break;
            }
        }
        for(int i = 0;i < n;i++){
            if(nums[i] < ch)
                ans++;
        }
        if(flag == 0)
            return -1;
        return ans;
    }
};