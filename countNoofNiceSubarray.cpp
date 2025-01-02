class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int prev_cnt = 0;
        int odd_cnt = 0;
        int ans = 0;

        int i = 0, j =0;
        while(j<nums.size()){
            if(nums[j]%2 != 0){ // odd no.
                odd_cnt++;
                prev_cnt=0;

            }
            while(odd_cnt == k){
                prev_cnt++;
                if(nums[i]%2 != 0){ // means nums[i]%2 == 1 odd no.
            odd_cnt--;
           }
           i++;
            }
        
                ans+=prev_cnt;
                j++;
        }
        return ans;
    }
};

// tc = O(n^2) sc=O(1)


/*Given an array of integers nums and an integer k. A continuous subarray is called nice if there are k odd numbers on it.

Return the number of nice sub-arrays.

 

Example 1:

Input: nums = [1,1,2,1,1], k = 3
Output: 2
Explanation: The only sub-arrays with 3 odd numbers are [1,1,2,1] and [1,2,1,1].
Example 2:

Input: nums = [2,4,6], k = 1
Output: 0
Explanation: There are no odd numbers in the array.
Example 3:

Input: nums = [2,2,2,1,2,2,1,2,2,2], k = 2
Output: 16
 

Constraints:

1 <= nums.length <= 50000
1 <= nums[i] <= 10^5
1 <= k <= nums.length
*/