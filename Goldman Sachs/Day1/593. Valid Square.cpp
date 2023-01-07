class Solution {
public:
double find_len(vector<int> p1, vector<int> p2){
return (((p2[0] - p1[0]) * (p2[0] - p1[0])) + ((p2[1] - p1[1]) * (p2[1] - p1[1])));
}
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
     //find lenght of all sides
     double d1=find_len(p1,p2); 
     double d2=find_len(p2,p3); 
     double d3=find_len(p3,p4); 
     double d4=find_len(p4,p1); 
     double d13 = find_len(p1, p3);
     double d24 = find_len(p2, p4);  
     unordered_set<double>s;
     s.insert({d1,d2,d3,d4,d13,d24});
     if(s.size()!=2 || s.count(0) ){
         return false;
     }
     return true;
    }
};