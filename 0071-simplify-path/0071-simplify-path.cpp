class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        string token = "";

        for (int i = 0; i <= path.size(); i++) {

            if (i == path.size() || path[i] == '/') {
                
                if (token == "" || token == ".") {
                }
                else if (token == "..") {
                    if (!st.empty()) st.pop();
                }
                else {
                    st.push(token);
                }
                token = "";
            }
            else {
                token += path[i];
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = "/" + st.top() + ans;
            st.pop();
        }

        return ans.empty() ? "/" : ans;
    }
};
