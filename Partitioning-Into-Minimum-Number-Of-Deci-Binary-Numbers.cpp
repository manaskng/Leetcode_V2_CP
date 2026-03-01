1class Solution {
2public:
3    int minPartitions(string n) {
4        int s=n.size();
5        int maxi=1;
6        for(int i=0;i<s;i++){
7            maxi=max(maxi,n[i]-'0');
8        }
9        return maxi;
10    }
11};