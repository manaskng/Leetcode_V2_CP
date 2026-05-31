class Solution {
public:
    const int MOD=1e9+7;

    int powi(long long  base, long long  exp){
        long long ans=1;
        while(exp>0){
            if(exp&1) ans=(ans*base)%MOD;

            base=(base*base)%MOD;
            exp>>=1;
        }
        return (int ) ans;
    }
    int countGoodNumbers(long long n) {
        long long evenways=(n+1)/2;
        long long oddways=(n/2);

        long long eventotal=powi(5,evenways);
        long long oddtotal=powi(4,oddways);

        return (eventotal*oddtotal)%MOD;

        
    }
};