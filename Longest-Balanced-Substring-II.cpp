1class Solution {
2public:
3    int longestBalanced(string s) {
4        int n = s.size();
5        int ans = 1;
6        
7        // for only a or only b or only c 
8        int count = 1;
9        for(int i=1;i<n;i++){
10            if(s[i] != s[i-1]) count = 0;
11            count++;
12            ans = max(ans,count);
13        }
14
15
16        int a = 0,b = 0,c = 0;
17        map<pair<int,int>,int> abc;
18        map<pair<int,int>,int> ab;
19        map<pair<int,int>,int> bc;
20        map<pair<int,int>,int> ac;
21
22        abc[{0,0}] = 0;
23        ab[{0,0}] = 0;
24        bc[{0,0}] = 0;
25        ac[{0,0}] = 0;
26
27        for(int i=0;i<n;i++){
28            if(s[i] == 'a') a++;
29            else if(s[i] == 'b') b++;
30            else c++;
31            
32            if(abc.find({a-b,b-c}) != abc.end()) ans = max(ans,(i+1)-abc[{a-b,b-c}]);
33            else abc[{a-b,b-c}] = i+1;
34            if(bc.find({b-c,a}) != bc.end()) ans = max(ans,(i+1)-bc[{b-c,a}]);
35            else bc[{b-c,a}] = i+1;
36            if(ac.find({a-c,b}) != ac.end()) ans = max(ans,(i+1)-ac[{a-c,b}]);
37            else ac[{a-c,b}] = i+1;
38            if(ab.find({a-b,c}) != ab.end()) ans = max(ans,(i+1)-ab[{a-b,c}]);
39            else ab[{a-b,c}] = i+1;
40        }
41
42        return ans;              
43    }
44};