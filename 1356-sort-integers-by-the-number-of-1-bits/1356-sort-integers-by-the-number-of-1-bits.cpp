class Solution {
public:
    static bool compare(int a, int b) {
        int counta = __builtin_popcount(a);
        int countb = __builtin_popcount(b);
        
        if (counta == countb) {
            return a < b;
        }
        return counta < countb;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), compare);
        return arr;
    }
};