class Solution {
public:
    double v[26][26][101];
    int x[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
    int y[8] = { 1, 2, 2, 1, -1, -2, -2, -1 };
    double dp(int i,int j, int k, int n){
        if(i < 0 || i >= n || j < 0 || j >= n) return 0;
        if(k==0)return 1;
        if(v[i][j][k])return v[i][j][k];
        double pro=0.0;
        for(int xx=0;xx<8;xx++){
            pro += dp(i+x[xx], j+y[xx], k-1,n);
        }
        return v[i][j][k]=pro/8;
    }
    double knightProbability(int n, int k, int row, int column) {
        return dp(row,column,k,n);
    }
};