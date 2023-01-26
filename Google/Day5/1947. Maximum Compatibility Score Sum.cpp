class Solution {
bool matched[9] = {};
int ans = 0, m, n;
    void dfs(vector<vector<int>>& S, vector<vector<int>>& M, int i, int score) {
        if (i == m) {
            ans = max(ans, score);
            return;
        }
        for (int j = 0; j < m; ++j) {
            if (matched[j]) continue;
            matched[j] = 1;
            int s = 0;
            for (int k = 0; k < n; ++k) s += S[i][k] == M[j][k];
            dfs(S, M, i + 1, score + s);
            matched[j] = 0;
        }
    }
public:
    int maxCompatibilitySum(vector<vector<int>>& students, vector<vector<int>>& mentors) {
        m = students.size(), n = students[0].size();
        dfs(students, mentors, 0, 0);
        return ans;
    }
};