class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long neg = 0, ans = 0;
        long long n = matrix.size();
        long long mini = 1000000;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j) {
                ans += abs(matrix[i][j]);
                if (matrix[i][j] < 0)
                    neg++;
                mini = mini < abs(matrix[i][j])? mini: abs(matrix[i][j]);
            }
        if (neg% 2 == 0)
            return ans;
        else 
            return ans - 2*mini;
    }
};