class Solution {
public:
    string addBinary(string a, string b) {
        string res="";
        int carry=0;
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        for(int i=0;i<max(a.size(),b.size());i++){
            int diga=i<a.size()?a[i]-'0':0;
            int digb=i<b.size()?b[i]-'0':0;
            int total=diga+digb+carry;
            char c=(total%2)+'0';
            res+=c;
            carry=total/2;

        }
        if(carry) res+='1';
        reverse(res.begin(),res.end());
        return res;
        
    }
};