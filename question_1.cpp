#include <bits/stdc++.h>
using namespace std;

/*

  Write a program: 
      Given a string containing just the characters '(' and ')', 
      return the length of the longest valid (well-formed) parentheses substring.

  Example 1:
  Input: s = "(()"
  Output: 2
  Explanation: The longest valid parentheses substring is "()".


  Example 2:
  Input: s = ")()())"
  Output: 4
  Explanation: The longest valid parentheses substring is "()()".

  Example 3:
  Input: s = ""
  Output: 0

  Constraints:
  0 <= s.length <= 3 * 104
  s[i] is '(', or ')'.

*/

/*

Approach : 

- idea is to make use of the fact that a match will only happen if we get ')' and we already have '('. 
- so we will keep track of the indices of where the '(' is present 
- when we came to know that current index has a ')', then 2 cases will be possible 
   1 -> match it with the last unmatched '(' if available 
   2 -> update the max length in case matching found


TC : O(n) [iterating through the array form left to the right]
SC : O(n) [max # of '(' in a string]

*/


auto getTheLengthOfLongestValidParenthesis = [](string s) -> int {
    int n = s.size();
    int max_len = 0;

    vector<int> st;
    st.push_back (-1); // to handle the unmatched ')'

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') st.push_back (i);
        else {
            st.pop_back();

            if (st.empty()) st.push_back (i); // not valid matching 
            else max_len = max(max_len, i - st.back());
        }
    }
    return max_len;
};

signed main() {

  string s;
  cin >> s;
    
  cout << getTheLengthOfLongestValidParenthesis(s) << '\n';
  return 0;
}