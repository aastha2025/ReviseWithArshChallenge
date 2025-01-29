/*Given a string s, Your task is to complete the function encode that returns the run length encoded string for the given string.
eg if the input string is “wwwwaaadexxxxxx”, then the function should return “w4a3d1e1x6″.
You are required to complete the function encode that takes only one argument the string which is to be encoded and returns the encoded string.

Example 1:

Input:
s = aaaabbbccc
Output: a4b3c3
Explanation: a repeated 4 times consecutively b 3 times, c also 3 times.
Example 2:

Input:
s = abbbcdddd
Output: a1b3c1d4
Explanation:  a repeated 1 time, b 3 times, c 1 time and d repeated 4 times.

Your Task:
Complete the function encode() which takes a string s as an input parameter and returns the encoded string.

Expected Time Complexity: O(n)
Expected Auxiliary Space: O(1)

Constraints:
1<=( n = length of s )<=106
 */

class Solution{
public:
string encode(string s) {
// code here
        int n = s.size();
        string st = "";
        int cnt =1;
        
        for(int i = 0 ; i <= n-2; i++){
            if(s[i] == s[i+1]){
                cnt+=1;
            }
            else{
                st+=s[i];
                st+=to_string(cnt);
                cnt=1;
            }
        }
        st+=s[n-1];
        return st+to_string(cnt);  
          }
};