class Solution {
public:
    int solve(int n, long long getit)
    {
        int total = 0;
        long long a = 10,b = n;
        for(int i=1;i<=9;i++)
        {
            long long mini = getit * a;
            long long maxi = mini + a-1;
            if(b < mini)break;
            total+= min(b,maxi) - mini + 1;
            a = a * 10;
        }
        
        return total+1;
    }
    
    int findKthNumber(int n, int k, int getit =0) {
        if(k>0)
        {
            for(int i= (getit==0)?1:0;i<=9;i++)
            {
                int cnt = solve(n,10*getit+i);
                if(k<=cnt) return findKthNumber(n,k-1,10*getit+i);
                k-=cnt;
            }            
        }
        
        return getit;
    }
};