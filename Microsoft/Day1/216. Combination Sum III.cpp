class Solution
{
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<vector<int>> res;
        vector<int> ans;
        helper(k, n, 1, ans, res);
        return res;
    }
    void helper(int k, int n, int start, vector<int> &ans, vector<vector<int>> &res)
    {
        if (n < 0 || ans.size() > k)
            return;

        if (n == 0 && ans.size() == k)
        {
            res.push_back(ans);
            return;
        }

        for (int i = start; i <= 9; ++i)
        {
            ans.push_back(i);
            helper(k, n - i, i + 1, ans, res);
            ans.pop_back();
        }
    }
};
