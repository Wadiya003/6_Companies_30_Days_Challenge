class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
          
        string ans = "";
        if((numerator<0 && denominator>0) || (numerator>0 && denominator<0 ))
            ans+= '-';
    
        long long a = abs(numerator);
        long long b = abs(denominator);
        long long num = abs(a/b);
        ans += to_string(num);
        long long rem = abs(a%b);
        if(rem == 0)
            return ans;
        
        ans.push_back('.');
        
        string dec = "";
        unordered_map<int, int> mp;
       
        
        while(rem!=0)
        {
            if(mp.find(rem) != mp.end())
            {
                int index  = mp[rem];
                string recurring = dec.substr(index);
                dec.erase(index);
                dec += '(' + recurring + ')';
                break;
            }
            else
            {
                mp[rem] = dec.size();
                dec += to_string(rem*10/b);
                rem = (rem*10)%b;
            }
        }
        
        ans += dec;
        return ans;
        
    }
};