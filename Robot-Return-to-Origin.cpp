1class Solution {
2public:
3    bool judgeCircle(string moves) {
4       int i=0,j=0;
5       for(int k=0;k<moves.size();k++){
6        if(moves[k]=='D') j++;
7        if(moves[k]=='U')j--;
8        if(moves[k]=='R')i++;
9        if(moves[k]=='L')i--;
10
11       }
12       return (i==0&&j==0);
13        
14    }
15};