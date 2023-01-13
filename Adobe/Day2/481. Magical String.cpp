class Solution {
public:
    int magicalString(int n) {
       if(n < 3) 
       return 1;
        int ans = 0;
        string s = "122";
        int i = 2;
        int ind=2;
        while(s.size() < n){
            if(s[i] == '1'){
                if(s[ind]=='2'){
                    s.push_back('1');
                }
                else{
                    s.push_back('2');
                }
            }
            else{
                if(s[ind]=='2'){
                   s += "11";
                }
                else{
                    s += "22";
                }
            }
            i++;
            ind = s.size() - 1;
        }
        for(int i=0;i<n;i++){
            if(s[i]=='1') ans++;
        }
        return ans;
    }
};
