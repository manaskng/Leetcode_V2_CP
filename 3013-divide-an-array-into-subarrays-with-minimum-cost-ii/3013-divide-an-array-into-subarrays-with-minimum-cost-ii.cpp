class Solution {
public:
    multiset<long long> small, large;
    long long sumSmall = 0;
    int need;

    void rebalance() {
        while ((int)small.size() > need) {
            auto it = prev(small.end()); 
            sumSmall -= *it;
            large.insert(*it);
            small.erase(it);
        }

        while ((int)small.size() < need && !large.empty()) {
            auto it = large.begin();  
            sumSmall += *it;
            small.insert(*it);
            large.erase(it);
        }
    }

    void add(long long x) {
        if (small.empty() || x <= *small.rbegin()) {
            small.insert(x);
            sumSmall += x;
        } else {
            large.insert(x);
        }
        rebalance();
    }

    void remove(long long x) {
        if (small.find(x) != small.end()) {
            small.erase(small.find(x));
            sumSmall -= x;
        } else {
            large.erase(large.find(x));
        }
        rebalance();
    }

    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();
        need = k - 1;

       
        for (int i = 1; i <= dist + 1; i++) {
            add(nums[i]);
        }

        long long ans = sumSmall;

        for (int r = dist + 2; r < n; r++) {
            add(nums[r]);
            remove(nums[r - (dist + 1)]);
            ans = min(ans, sumSmall);
        }

        return nums[0] + ans;
    }
};
