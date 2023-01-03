class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        map<pair<int, int>, int> vertices;
        for(vector<int>& x:rectangles){
            vertices[{x[0], x[1]}]++;         
            vertices[{x[0], x[3]}]--;     
            vertices[{x[2], x[1]}]--;     
            vertices[{x[2], x[3]}]++; 
        }
        int valid_vertex=0;
        for(auto ptr=vertices.begin();ptr!=vertices.end();ptr++){
          if(abs(ptr->second)>1)
          return false;
          if(abs(ptr->second)==1){
                valid_vertex++;
                // cout<<valid_vertex<<endl;
        }}
        return valid_vertex==4;  
    }
};