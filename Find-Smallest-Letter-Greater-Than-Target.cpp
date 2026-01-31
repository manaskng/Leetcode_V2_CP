1class Solution {
2public:
3    char nextGreatestLetter(vector<char>& letters, char target) {
4        int n=letters.size();
5        char ans=letters[0];
6        if(ans-'a'>target-'a')return ans;
7        for(int i=0;i<n;i++){
8            if(letters[i]-'a'>target-'a'){
9                ans=letters[i];
10                break;
11            }
12        }
13        return ans;
14        
15    }
16};