class Solution {
public:
    int minPartitions(string n) {
        int s=n.size();
        int maxi=1;
        for(int i=0;i<s;i++){
            maxi=max(maxi,n[i]-'0');
        }
        return maxi;
    }
};