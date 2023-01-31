
class Node {
public:
    int isTerminal;
    vector<Node *> children;
    Node() {
        children.resize(26, NULL);
        isTerminal = 0;
    }
};

class Trie {

public:
    Trie() {
        root = new Node();
    }

    Node *root;
    void insert(string s) {
        Node *cur = root;
        for (char ch : s) {
            if (!cur->children[ch - 'a']) cur->children[ch - 'a'] = new Node();
            cur = cur->children[ch - 'a'];
        }
        (cur->isTerminal)++;
    }

    int dfs(Node *root, string &s, int idx, vector<int>pos[]) {
        int res = 0;
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                int newIdx = upper_bound(pos[i].begin(), pos[i].end(), idx) - pos[i].begin();
                if (newIdx == pos[i].size()) continue;
                res += dfs(root->children[i], s, pos[i][newIdx], pos);
            }
        }
        return res + root->isTerminal;
    }
};




class Solution {
public:
    //trie problem
    int numMatchingSubseq(string s, vector<string>& words) {
        Trie *t = new Trie;
        for (string str : words) {
            t->insert(str);
        }
        vector<int> v[26];
        for (int i = 0; i < s.length(); i++) {
            v[s[i] - 'a'].push_back(i);
        }
        return t->dfs(t->root, s, -1, v);
    }
};