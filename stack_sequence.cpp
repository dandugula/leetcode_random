class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        std::stack<int> st;
        int pp = 0;
        int ps = 0;

        while(ps < pushed.size()) {
           if (!st.empty() && popped[pp] == st.top()) {
                st.pop();

                pp++;

           }
           else {
               st.push(pushed[ps++]);
           }
        }

        while (pp < popped.size())
            if (popped[pp++] == st.top()) st.pop();
            else break;

        return st.empty() ? true : false;
    }
};