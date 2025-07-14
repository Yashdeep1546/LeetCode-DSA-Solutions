class Solution {
    public:
        int evalRPN(vector<string>& tokens) {
            stack<int> st;
            for (const string& token : tokens) {
                if (token == "+" || token == "-" || token == "*" || token == "/") {
                    int c1 = st.top(); st.pop();
                    int c2 = st.top(); st.pop();
                    if (token == "+") st.push(c2 + c1);
                    else if (token == "-") st.push(c2 - c1);
                    else if (token == "*") st.push(c2 * c1);
                    else if (token == "/") st.push(c2 / c1);
                } else {
                    st.push(stoi(token));
                }
            }
            return st.top();
        }
    };
    