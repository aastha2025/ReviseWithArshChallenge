class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
// tc = O(n)+O(1)+O(n) = O(n) ;   sc= O(n)
         vector<string> str;
        unordered_map<string,int> mpp;
        for(int i=0;i <= s.length();i++){
            mpp[s.substr(i,10)]++;
        }

        for(auto& it:mpp){
            if(it.second > 1){
                str.push_back(it.first);
            }
        }

        return str;
    }
};


/*The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.

 

Example 1:

Input: s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
Output: ["AAAAACCCCC","CCCCCAAAAA"]
Example 2:

Input: s = "AAAAAAAAAAAAA"
Output: ["AAAAAAAAAA"]
 

Constraints:

1 <= s.length <= 105
s[i] is either 'A', 'C', 'G', or 'T'.*/