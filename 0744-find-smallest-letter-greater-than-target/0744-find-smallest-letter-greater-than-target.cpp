class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        char ans=letters[0];
        if(ans-'a'>target-'a')return ans;
        for(int i=0;i<n;i++){
            if(letters[i]-'a'>target-'a'){
                ans=letters[i];
                break;
            }
        }
        return ans;
        
    }
};