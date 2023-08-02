/*
3. Longest Substring Without Repeating Characters

Given a string s, find the length of the longest 
substring without repeating characters.

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Constraints:

0 <= s.length <= 5 * 10^4
s consists of English letters, digits, symbols and spaces.
*/

#include <string>
#include <vector>

using namespace std; 

// time O(n) linear 
// space O(min(n, m)) n is char set of string ; m is size of alphabet 
class Solution {
public: 
    int lengthOfLongestSubstring(string s) {
        int ans = 0, start = -1; 
        vector<int> prevIdx(128, -1);
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i]; 
            start = max(start, prevIdx[c]); 
            ans = max(ans, i - start); 
            prevIdx[c] = i; 
        }
        return ans; 
    }
};