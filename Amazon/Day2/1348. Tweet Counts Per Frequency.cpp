class TweetCounts {
public:
    map<string, vector<int>> m;
    TweetCounts() {
        
    }
    
    void recordTweet(string tweetName, int time) {
        m[tweetName].push_back(time);
    }
    
    vector<int> getTweetCountsPerFrequency(string freq, string tweetName, int startTime, int endTime) {
        //seconds
        int d = 86400;
        if (freq[0] == 'm') {
            d = 60;
        } else if (freq[0] == 'h') {
            d = 3600;
        }
        //ans vector size= total ranges
        vector<int>ans(((endTime-startTime)/d) +1);
        vector<int>time=m[tweetName];
        for(auto it=time.begin();it!=time.end();it++){
            //if between range
            if((*it)>=startTime  &&   (*it)<=endTime){
                ans[((*it)-startTime)/d]++;
            }
        }
        return ans;
    }
};

/**
 * Your TweetCounts object will be instantiated and called as such:
 * TweetCounts* obj = new TweetCounts();
 * obj->recordTweet(tweetName,time);
 * vector<int> param_2 = obj->getTweetCountsPerFrequency(freq,tweetName,startTime,endTime);
 */