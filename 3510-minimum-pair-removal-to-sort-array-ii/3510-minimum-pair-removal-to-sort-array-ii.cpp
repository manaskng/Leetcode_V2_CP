class Solution {
public:
 typedef long long ll;
    int minimumPairRemoval(vector<int>& nums) {
        vector<ll> arr(nums.begin(), nums.end());
        ll n = arr.size();
        ll bad = 0;
        vector<ll> prevIndex(n, 0), nextIndex(n, 0);
        set<pair<ll, ll>> st;
        for (int i = 0; i < n; i++) {
            prevIndex[i] = i - 1;
            nextIndex[i] = i + 1;
            if (i > 0) {
                if (arr[i] < arr[i - 1]) {
                    bad++;
                }
                st.insert({arr[i] + arr[i - 1], i - 1});
            }
        }
        ll ans = 0;
        while (bad > 0) {
            if (st.empty()) {
                break;
            }
            auto [sum, firstIndex] = *st.begin();
            st.erase(st.begin());
            ll secondIndex = nextIndex[firstIndex];
            ll firstLeft = prevIndex[firstIndex];
            // if (firstIndex >= 0) {
            //     firstLeft = prevIndex[firstIndex];
            // }
            ll secondRight = nextIndex[secondIndex];
            // if (secondIndex < n) {
            //     secondRight = nextIndex[secondIndex];
            // }
            if (firstLeft >= 0) {
                auto it = st.find(
                    {(ll)arr[firstLeft] + (ll)arr[firstIndex], firstLeft});
                if (it != st.end()) {
                    st.erase(it);
                }

                st.insert({(ll)arr[firstLeft] + sum, firstLeft});
            }
            if (secondRight < n) {
                auto it = st.find(
                    {(ll)arr[secondIndex] + (ll)arr[secondRight], secondIndex});
                if (it != st.end()) {
                    st.erase(it);
                }
                st.insert({(ll)arr[secondRight] + sum, firstIndex});
            }

            if (firstLeft >= 0 && arr[firstIndex] < arr[firstLeft]) {
                bad--;
            }

            if (arr[secondIndex] < arr[firstIndex]) {
                bad--;
            }
            if (secondRight < n && arr[secondRight] < arr[secondIndex]) {
                bad--;
            }

            if (firstLeft >= 0 && sum < arr[firstLeft]) {
                bad++;
            }
            if (secondRight < n && arr[secondRight] < sum) {
                bad++;
            }

            arr[firstIndex] = sum;
            nextIndex[firstIndex] = secondRight;
            if (secondRight < n) {
                prevIndex[secondRight] = firstIndex;
            }

            ans++;
        }
        return ans;
    }
};