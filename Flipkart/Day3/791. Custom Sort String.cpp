class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        map<int,char> m1;
        unordered_map<char,int> m2;
        int i = 0;
        //store position of order string
        for(auto o:order) m1[i++]=o;
        //store frequency of string s
        for(auto &s:s) m2[s]++;
        //for every char in order, if exists same char in s, add to ans
        for(auto &m:m1){
            while(m2[m.second]>0){
                ans+=m.second;
                m2[m.second]--;
            }
        }
        //add left out chars as well
        for(auto &m:m2){
            while(m.second>0){
                ans+=m.first;
                m.second--;
            }
        }
        return ans;
    }
};