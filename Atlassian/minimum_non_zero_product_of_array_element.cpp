class Solution {
public:
    long long MOD = 1000000007;
    long long solve(long long base, long long exp){
        if(exp==0) return 1;
        if(exp==1) return base%MOD;
        if(exp%2 ==0){
            long long temp = solve(base,exp/2);
            return (temp*temp)%MOD;
        }
        else{
            long long temp = solve(base,exp/2);
            temp = (temp*temp)%MOD;
            return (temp*(base%MOD))%MOD;
        }
    }

    int minNonZeroProduct(int p) {
        long long val = pow(2,p);    
        val--;                          
        long long exp = val/2;  

        long long base = val-1;            
        long long ans = solve(base,exp);      
        return ans*((val)%MOD)%MOD;     
    }
};