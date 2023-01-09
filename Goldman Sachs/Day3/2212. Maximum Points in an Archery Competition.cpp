class Solution {
public:
int let = INT_MIN;
vector<int> res;
void recur(int board,int arrow, vector<int>& aliceArrows, int cur,  vector<int> &ans){
    if(board<0 ||arrow<=0){
        if(let<max(let,cur)){
            for(int j=0; j<12; j++)
                res[j]=ans[j];
            res[0]+= arrow; //if any extra arrow left
        }
        let=max(let,cur);
        return;
    }
    // else if(board<0)
    // return;
    if(arrow>aliceArrows[board]){
        ans[board]=aliceArrows[board]+1;
        //use arrow here
        recur(board-1,arrow-aliceArrows[board]-1, aliceArrows, cur+board, ans);
        ans[board]=0;
        //backtrack
    }
    //don't use arrow
    recur(board-1,arrow, aliceArrows, cur, ans);
}
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
    res.resize(12, 0);
    vector<int> ans(12, 0);
    recur(11,numArrows,aliceArrows,0 ,ans);
    return res;
    }
};