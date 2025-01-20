/*You are given the root of a binary tree and an integer distance. A pair of two different leaf nodes of a binary tree is said to be good if the length of the shortest path between them is less than or equal to distance.

Return the number of good leaf node pairs in the tree.

 

Example 1:


Input: root = [1,2,3,null,4], distance = 3
Output: 1
Explanation: The leaf nodes of the tree are 3 and 4 and the length of the shortest path between them is 3. This is the only good pair.
Example 2:


Input: root = [1,2,3,4,5,6,7], distance = 3
Output: 2
Explanation: The good pairs are [4,5] and [6,7] with shortest path = 2. The pair [4,6] is not good because the length of ther shortest path between them is 4.
Example 3:

Input: root = [7,1,4,6,null,5,3,null,null,null,null,null,2], distance = 3
Output: 1
Explanation: The only good pair is [2,5].
 

Constraints:

The number of nodes in the tree is in the range [1, 210].
1 <= Node.val <= 100
1 <= distance <= 10*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*, vector<TreeNode*>> map;
        vector<TreeNode*> leaves;
        findLeaves(root, {}, leaves, map);
        int res = 0;
        for (int i = 0; i < leaves.size(); i++) {
            for (int j = i + 1; j < leaves.size(); j++) {
                vector<TreeNode*>& list_i = map[leaves[i]];
                vector<TreeNode*>& list_j = map[leaves[j]];
                for (int k = 0; k < min(list_i.size(), list_j.size()); k++) {
                    if (list_i[k] != list_j[k]) {
                        int dist = list_i.size() - k + list_j.size() - k;
                        if (dist <= distance) res++;
                        break;
                    }
                }
            }
        }
        return res;
    }

private:
    void findLeaves(TreeNode* node, vector<TreeNode*> trail, vector<TreeNode*>& leaves, unordered_map<TreeNode*, vector<TreeNode*>>& map) {
        if (!node) return;
        vector<TreeNode*> tmp(trail);
        tmp.push_back(node);
        if (!node->left && !node->right) {
            map[node] = tmp;
            leaves.push_back(node);
            return;
        }
        findLeaves(node->left, tmp, leaves, map);
     findLeaves(node->right, tmp, leaves, map);

    }
};