/*Convert a non-negative integer num to its English words representation.

 

Example 1:

Input: num = 123
Output: "One Hundred Twenty Three"
Example 2:

Input: num = 12345
Output: "Twelve Thousand Three Hundred Forty Five"
Example 3:

Input: num = 1234567
Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
 

Constraints:

0 <= num <= 231 - 1*/


class Solution {
public:
     string ones[20] = {"", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine", " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen"};
    string tens[10] = {"", " Ten", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety"};
    string thousands[4] = {"", " Thousand", " Million", " Billion"};
  
  string helper(int n) {
        if (n < 20) 
            return ones[n];
        if (n < 100) 
            return tens[n / 10] + helper(n % 10);
        if (n < 1000) 
            return helper(n / 100) + " Hundred" + helper(n % 100);
        for (int i = 3; i >= 0; i--) {
            if (n >= pow(1000, i)) {
                return helper(n / pow(1000, i)) + thousands[i] + helper(n % (int)pow(1000, i));
            }
        }
        return "";
    }

    string numberToWords(int num) {
        if (num == 0) 
            return "Zero";
        return helper(num).substr(1);
    }
};