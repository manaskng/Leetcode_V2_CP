class Solution {
public:
    vector<string> ans;

    pair<int,int> check(vector<int>& bits) {

        int hours = 0;
        int power = 3;

        for(int i = 0; i <= 3; i++) {
            hours += bits[i] * (1 << power);
            power--;
        }

        int minutes = 0;
        int power1 = 5;

        for(int i = 4; i <= 9; i++) {
            minutes += bits[i] * (1 << power1);
            power1--;
        }

        return {hours, minutes};
    }

    void rec(int i, int cnt, vector<int>& bits, int turnedOn) {

        if(i == 10) {

            if(cnt == turnedOn) {

                pair<int,int> time = check(bits);
                int hours = time.first;
                int minutes = time.second;

                if(hours <= 11 && minutes <= 59) {

                    string s = "";
                    s += to_string(hours);
                    s += ":";

                    if(minutes >= 10)
                        s += to_string(minutes);
                    else
                        s += "0" + to_string(minutes);

                    ans.push_back(s);
                }
            }
            return;
        }

        rec(i+1, cnt, bits, turnedOn);

        bits[i] = 1;
        rec(i+1, cnt+1, bits, turnedOn);
        bits[i] = 0;
    }

    vector<string> readBinaryWatch(int turnedOn) {

        vector<int> bits(10, 0);
        rec(0, 0, bits, turnedOn);
        return ans;
    }
};
