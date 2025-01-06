/*/*Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:
Input: s = "leetcode"
Output: 0
Explanation:
The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:
Input: s = "loveleetcode"
Output: 2

Example 3:
Input: s = "aabb"
Output: -1

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.*/
*/

class Solution {
public:
    int firstUniqChar(string s) {

// tc = O(n) SC = O(1)
        vector<int>freq(26, 0);
         for(auto it : s){
            freq[it-'a']++;
         }
         for(int i = 0 ; i < s.size(); i++){
            if(freq[s[i]-'a'] == 1) return i;
         }
            return -1;

        //type 2 
        // tc = O(n) sc=O(n)
        // unordered_map<char, int>mpp;
        // for(auto it : s){
        //     mpp[it]++;
        // }
        // for(int i = 0 ; i < s.size(); i++){
        //     if(mpp[s[i]] == 1) return i;
        // }
        // return -1;
    }
};