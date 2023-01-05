class Solution {
private:
    list<int>* adj_list;
    vector<int>  parent_list,time;
public:
    void find_parent(int node){
        for(auto n: adj_list[node]){
            if(n!= parent_list[node]){
                 parent_list[n]=node;
                find_parent(n);
            }
        }
    }
    
    int dfs(int node,int t, vector<int> &amount){
        int res=INT_MIN;
        int temp=0;
        if(time[node]==t){  // alice and bob reached at same time
            temp=amount[node]/2;
        }
        else if(time[node]>t){  // alice reached earlier than bob 
            temp=amount[node];
        }
        if(adj_list[node].size()==1 &&  parent_list[node]==*adj_list[node].begin()){  
            return temp;   //leaf node
        }
        for(auto n: adj_list[node]){
            if(n!= parent_list[node]){
                res=max(res,temp+dfs(n,t+1,amount));
            }
        }
        return res;
    }
    
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n=amount.size();
        adj_list=new list<int>[n];
        parent_list.resize(n,-1);
        int node=bob;
        for(auto edge: edges){  
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        find_parent(0);
        time.resize(n,INT_MAX);
        int t=0;
        while(node!=-1){
            time[node]=t++;
            node=parent_list[node];
        }
        return dfs(0,0,amount);
    }
};