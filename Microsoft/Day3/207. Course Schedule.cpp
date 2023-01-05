class Solution {
public: //firstly ,choose all independent course 
    //then chooe those course whoch dont have any incoming edge
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
          int n=prerequisites.size();
          queue<int>q;
          int cnt=0;
          vector<vector<int>> graph(numCourses);
          vector<int>incoming(numCourses,0);
          for(int i=0;i<n;i++){
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]); //adcacency list
            ++incoming[prerequisites[i][0]];
           }
        
          for(int i = 0;i < numCourses;i++){
            if(incoming[i] == 0)
                q.push(i);
          }
        
         while(!q.empty()){
         int node=q.front();
            q.pop();
            ++cnt;
          for(auto v : graph[node])
            {
                if(--incoming[v] == 0)
                    q.push(v);
            }
         }
        
        return cnt==numCourses; 
    }
   
    
    
};