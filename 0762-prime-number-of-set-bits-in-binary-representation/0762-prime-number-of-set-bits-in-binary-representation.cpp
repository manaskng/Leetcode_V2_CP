class Solution {
public:
   bool isprime(int n){
    if(n<=1) return false;
    for(int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
   }
    int countPrimeSetBits(int left, int right) {
        int netcnt=0;
        for(int i=left;i<=right;i++){
            // count the set bits 
            int cnt=0;
            int num=i;
            while(num){
                int mod=num%2;
                if(mod==1)cnt++;
                num/=2;
            }
            netcnt+=(isprime(cnt)?1:0);

        }
        return netcnt;
    }
};