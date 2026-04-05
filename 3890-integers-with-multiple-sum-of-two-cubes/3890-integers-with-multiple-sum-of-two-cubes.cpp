class Solution {
public:
    vector<int> findGoodIntegers(int n) {
         vector<int> ans;
        unordered_map<int,int> cnt;

        for(int i = 1; i <= 999; i++){
            for(int j = i; j <= 999; j++){
                long long sum = (long long)i*i*i + (long long)j*j*j;
                if(sum <= n){
                    cnt[sum]++;
                }
            }
        }

        for(auto it : cnt){
            if(it.second >= 2){
                ans.push_back(it.first);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
        
    }
};