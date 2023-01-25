class Solution {
public:
    void recur(string s, int i, int cnt, string cur, vector<string>& res) {
        if (cnt == 4 && i == s.length()) {
            res.push_back(cur.substr(0,cur.length()-1));
            return;
        }
        if (cnt > 4) 
            return;

        for (int j = i; j < min(i+3, (int)s.length()); j++) {
            if (stoi(s.substr(i, j-i+1)) < 256 && (i == j || s[i] != '0')) {
                recur(s, j+1, cnt+1, cur + s.substr(i, j-i+1) + ".", res);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string>ans;
        if (s.length() > 12)
            return ans;
        recur(s, 0, 0, "", ans);
        return ans;
    }
};