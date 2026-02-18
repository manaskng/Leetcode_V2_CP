class Solution {
public:
    bool hasAlternatingBits(int n) {
        int prevmod=n%2;
        n/=2;
        while(n){
            int currmod=n%2;
            if(prevmod==currmod) return false;
            n/=2;
            prevmod=currmod;
        }
        return true;
    }
};