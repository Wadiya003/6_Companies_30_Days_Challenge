class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last(3,-1);
        int res = 0, n = s.length();
        for (int i = 0; i < n; ++i) {
            last[s[i] - 'a'] = i;
            res += 1 + min({last[0], last[1], last[2]});
        }
        return res;
    }
};