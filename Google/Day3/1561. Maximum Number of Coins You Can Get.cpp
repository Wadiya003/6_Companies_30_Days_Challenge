class Solution {
public:
    int maxCoins(vector<int>& piles) {
    //2 pointer
    int sum=0;
    int i=0;
    int j=piles.size()-1;

    sort(piles.begin(),piles.end());
    while(i<=j){
        sum+=piles[j-1];
        i++;
        j-=2;
    }
    return sum;
    }
};
