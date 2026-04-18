class Solution {
public:
    int mirrorDistance(int n) {
        string ori = to_string(n);
        string rev=ori;
        reverse(rev.begin(),rev.end());
        int m=rev.size();
        int rev_num=stoi(rev);
        return abs(n-rev_num);
        
    }
};