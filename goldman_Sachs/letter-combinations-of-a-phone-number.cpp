/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.


 

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:

0 <= digits.length <= 4
digits[i] is a digit in the range ['2', '9'].*/

class Solution {
public:
vector<string>result;
void solve(int idx, string& digits, string& temp, unordered_map<char, string>&mpp){
    if(idx >= digits.length()){
        result.push_back(temp);
        return;
    }

    char ch = digits[idx];
    string str = mpp[ch];

    for(int i = 0 ; i < str.length(); i++){
        temp.push_back(str[i]);
        solve(idx+1, digits, temp, mpp);
        temp.pop_back();
    }
   }
   
   
     vector<string> letterCombinations(string digits) {
        std::map<int, std::vector<char>> mp;
        mp[2] = {'a', 'b', 'c'};
        mp[3] = {'d', 'e', 'f'};
        mp[4] = {'g', 'h', 'i'};
        mp[5] = {'j', 'k', 'l'};
        mp[6] = {'m', 'n', 'o'};
        mp[7] = {'p', 'q', 'r', 's'};
        mp[8] = {'t', 'u', 'v'};
        mp[9] = {'w', 'x', 'y', 'z'};

        if (digits.empty()) return {};

        int firstDigit = digits[0] - '0';
        vector<string> result;
        for (char c : mp[firstDigit]) {
            result.push_back(string(1, c));
        }

        for (size_t i = 1; i < digits.size(); i++) {
            int digit = digits[i] - '0';
            vector<string> temp;
            for (const string& prefix : result) {
                for (char c : mp[digit]) {
                    temp.push_back(prefix + c);
                }
            }
            result = temp;
        }

        return result;
  }
};