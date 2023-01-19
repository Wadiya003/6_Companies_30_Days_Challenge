class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
    // Sieve of eratosthenes
    // vector<int>p;
    vector<bool> primes(right+1,true);
    primes[0]=primes[1]=false;
    for(int i=2;i<=right;i++){
        if(!primes[i]) {continue;}
        for(long long j=1LL*i*i;j<=right;j+=i){
            primes[j] = false;
        }
    } 
    int l=-1;
    int r=-1;
    int pre=-1;
    for(int i=left; i<=right; i++){
        if(!primes[i]) continue;
        if(l==-1) l = i;
        else if(r==-1){
            r = i;
        }
        else if(i-pre < r-l){
            l=pre;
            r=i;
        }
        pre = i;
    }

    if(r==-1) return {-1, -1};
    else return {l, r};
    }
};