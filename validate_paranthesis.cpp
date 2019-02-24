class Solution {
public:
  int minAddToMakeValid(string S) {
    std::stack<char> st;
    int res = 0;

    for(auto ch : S) 
      if(ch == '(') st.push(ch);
      else 
        if(!st.empty()) st.pop();
        else ++res;

    res += st.size();
    return res;
  }
};
