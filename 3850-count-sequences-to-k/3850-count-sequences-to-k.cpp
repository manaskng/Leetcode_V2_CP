class Solution {
public:
    int countSequences(vector<int>& nums, long long k) {
        
        auto factorize = [](long long x, int& a, int& b, int& c) -> bool {
            a = b = c = 0;
            while(x % 2 == 0) { x /= 2; a++; }
            while(x % 3 == 0) { x /= 3; b++; }
            while(x % 5 == 0) { x /= 5; c++; }
            return x == 1;
        };
        
        int ka, kb, kc;
        if(!factorize(k, ka, kb, kc)) return 0;
        
        // State: encode (a,b,c) with offset 19, into single int key
        // a,b,c in [-19,19], offset=19 => [0,38]
        // key = a*39*39 + b*39 + c (after offset)
        const int OFF = 19, BASE = 39;
        
        auto encode = [&](int a, int b, int c) -> int {
            return (a+OFF)*BASE*BASE + (b+OFF)*BASE + (c+OFF);
        };
        
        // Use unordered_map for sparse states
        unordered_map<int,long long> dp;
        dp[encode(0,0,0)] = 1;
        
        for(int i = 0; i < (int)nums.size(); i++) {
            int na, nb, nc;
            factorize(nums[i], na, nb, nc);
            
            unordered_map<int,long long> ndp;
            ndp.reserve(dp.size() * 3);
            
            for(auto& [key, cnt] : dp) {
                // Decode
                int tmp = key;
                int c = tmp % BASE - OFF; tmp /= BASE;
                int b = tmp % BASE - OFF; tmp /= BASE;
                int a = tmp - OFF;
                
                // Leave unchanged
                ndp[key] += cnt;
                
                // Multiply
                int ma=a+na, mb=b+nb, mc=c+nc;
                if(ma>=-19&&ma<=19&&mb>=-19&&mb<=19&&mc>=-19&&mc<=19)
                    ndp[encode(ma,mb,mc)] += cnt;
                
                // Divide
                int da=a-na, db=b-nb, dc=c-nc;
                if(da>=-19&&da<=19&&db>=-19&&db<=19&&dc>=-19&&dc<=19)
                    ndp[encode(da,db,dc)] += cnt;
            }
            dp = move(ndp);
        }
        
        int target = encode(ka, kb, kc);
        auto it = dp.find(target);
        return it != dp.end() ? (int)it->second : 0;
    }
};