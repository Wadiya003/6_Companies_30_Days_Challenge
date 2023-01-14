class StockPrice {
public:
        unordered_map<int ,int>m;
        priority_queue<pair<int,int>>p;
        priority_queue<pair<int ,int>, vector<pair<int,int>>, greater<pair<int,int>>>min_p;
        int cur=0;
        int cur_price=0;
    StockPrice() {
        
    }
    
    void update(int timestamp, int price) {
      m[timestamp]=price;
      p.push({price,timestamp});
      min_p.push({price,timestamp});
        if(timestamp>=cur){
            cur=timestamp;
            cur_price=price;
        }
        while (m[p.top().second] != p.top().first)
        {
            p.pop();
        }
        while (m[min_p.top().second] !=min_p.top().first)
        {
            min_p.pop();
        }  
    }
    
    int current() {
        return cur_price;
    }
    
    int maximum() {
        return p.top().first;
    }
    
    int minimum() {
        return min_p.top().first;
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */