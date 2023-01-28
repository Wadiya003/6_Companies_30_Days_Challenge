class Solution {
public:
       
    int ans=1;
    void helper(string &s,int i,vector<string> &temp,unordered_set<string> &st)
    {
        if(i == s.length()){
            int len=temp.size();
            ans = max(ans,len);
            return;
        }
        string ss="";
        for(int j=i;j<s.length();j++){
            ss.push_back(s[j]);
            if(!st.count(ss)){                            
                temp.push_back(ss);
                st.insert(ss);
                helper(s,j+1,temp,st);
                st.erase(ss);                         
                temp.pop_back();                    
            }
        }
    }
    int maxUniqueSplit(string s) {
        vector<string> temp;
        unordered_set<string> st;
        helper(s,0,temp,st);
        return ans;
        
    }
};