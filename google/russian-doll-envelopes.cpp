/*You are given a 2D array of integers envelopes where envelopes[i] = [wi, hi] represents the width and the height of an envelope.

One envelope can fit into another if and only if both the width and height of one envelope are greater than the other envelope's width and height.

Return the maximum number of envelopes you can Russian doll (i.e., put one inside the other).

Note: You cannot rotate an envelope.

 

Example 1:

Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
Output: 3
Explanation: The maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
Example 2:

Input: envelopes = [[1,1],[1,1],[1,1]]
Output: 1
 

Constraints:

1 <= envelopes.length <= 105
envelopes[i].length == 2
1 <= wi, hi <= 105
*/


class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& nums) {
        
        // sort the array if num[i][0] == nums[i+1][0] push greater height first else push greater width
        sort(nums.begin(), nums.end(), [](const vector<int>&n,const vector<int>&m) {
            if(n[0] == m[0]) return n[1] > m[1];
            return n[0] < m[0];
        });

        vector<int>height;
        // store only height becuz it has condition for width they are either equal or in ascending order;
        for(int i=0; i<nums.size(); i++) {
            height.push_back(nums[i][1]);
        }

        vector<int>longest_en;
        // check for all possible values in longy vector
        for(auto i : height) {

            //first first element greater than or equal to i in longy
            auto it = lower_bound(longest_en.begin(),longest_en.end(),i);

            if(it == longest_en.end()) longest_en.push_back(i);  //if not push at back
            else *it = i; //replace first element which is greater or equal to i in longy
        }

        return longest_en.size(); //calculate total envelop we pushed
    }
};