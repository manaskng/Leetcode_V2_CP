class Solution {
public:
     int factorial(int n){
         if(n<=1) return 1;
         return n*factorial(n-1);
     }

    bool isDigitorialPermutation(int n) {

        int sum = 0;
        int zerocnt = 0;
        int num = n;

        while(n){
            int mod = n % 10;
            if(mod == 0) zerocnt++;
            sum += factorial(mod);
            n /= 10;
        }

        if(num == sum) return true;

        string sum1 = to_string(sum);
        string num1 = to_string(num);

        unordered_map<char,int> mpp1;

        for(int i = 0; i < sum1.size(); i++){
            mpp1[sum1[i]]++;
        }

        for(int i = 0; i < num1.size(); i++){
            if(mpp1.find(num1[i]) == mpp1.end()){
                return false;
            }
            mpp1[num1[i]]--;
        }

        for(auto it : mpp1){
            if(it.second != 0) return false;
        }

        return true;   
    }
};