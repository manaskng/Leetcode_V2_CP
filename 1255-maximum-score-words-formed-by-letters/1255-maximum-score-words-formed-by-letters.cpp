class Solution {
public:

    bool check (string s, unordered_map<char,int> letterfreq){
        for(int i=0;i<s.size();i++){
            if(letterfreq.find(s[i])!=letterfreq.end()){
                letterfreq[s[i]]--;
                if(letterfreq[s[i]]==0) {
                    letterfreq.erase(s[i]);
                }
            }else {
                // if any letter from string is not present or becomes 0 then we cannot take it
                return false;
            }
        }
        return true;
    }

    int rec(int i, vector<string>&words, vector<char>&letters, vector<int>&score,
            unordered_map<char,int>&letterfreq, vector<int>&sc){

        if(i >= words.size()) return 0; // base case fixed

        int nottake = rec(i+1, words, letters, score, letterfreq, sc);

        int take = 0;

        // we can only take a word if we have enough availabe to take from letterfreq 
        if(check(words[i], letterfreq)){

            // decrement the neccessary freq's from the letterfreq as we took some words[i] worth of letters
            for(auto c:words[i]){
                letterfreq[c]--;
                if(letterfreq[c]==0) letterfreq.erase(c);
            }

            take = sc[i] + rec(i+1, words, letters, score, letterfreq, sc);

           
            for(auto c:words[i]){
                letterfreq[c]++;
            }
        }

        return max(take, nottake);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        int n = words.size();

        unordered_map<char,int> letterfreq;
        for(char c:letters) letterfreq[c]++; //counting each of the letters

        // make a score array of each of the words commute score of each word
        vector<int> sc(n);

        for(int i=0;i<n;i++){
            int currscore = 0;
            for(int j=0;j<words[i].size();j++){
                if(letterfreq.find(words[i][j])==letterfreq.end()){
                    sc[i] = -1;
                    break;
                }
                currscore += score[words[i][j]-'a'];
            }
            sc[i] = currscore;
        }

       
        return rec(0, words, letters, score, letterfreq, sc);
    }
};