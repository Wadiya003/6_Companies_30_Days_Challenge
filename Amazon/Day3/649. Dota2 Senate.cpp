class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> r, d;
        for(int i=0; i<senate.size(); i++)
            senate[i] == 'R' ? r.push(i): d.push(i);
        
        int a, b;
        while(!r.empty() and !d.empty()){
            a = r.front(), b = d.front();
            r.pop(), d.pop();
            if (a < b) 
                r.push(a+senate.size());
            else
                d.push(b+senate.size());
        }
        
		if (r.size() > d.size())
			return "Radiant";
		else
			return "Dire";
    }
};