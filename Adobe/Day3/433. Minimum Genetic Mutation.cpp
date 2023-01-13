class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        queue<string> q;
        unordered_set<string> seen;
        q.push(startGene);
        seen.insert(startGene);
        int  ans = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int j = 0; j < sz; j++) {
                string node = q.front();
                q.pop();
                if (node == endGene) {
                    return ans;
                }
                for (char c: "ACGT") {
                    for (int i = 0; i < node.size(); i++) {
                        string neighbor = node;
                        neighbor[i] = c;
                        if (!seen.count(neighbor) && find(bank.begin(), bank.end(),                       neighbor) != bank.end()) {
                            q.push(neighbor);
                            seen.insert(neighbor);
                        }
                    }
                }
            }
            ans++;
        }
        
        return -1;
    }
};