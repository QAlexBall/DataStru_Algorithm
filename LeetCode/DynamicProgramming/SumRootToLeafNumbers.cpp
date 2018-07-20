/**
 * Sum Root to Leaf Numbers
 * 
 * Description: Given a binary tree containing digits from 0-9 only,each root-to-leaf path could represent a number.
 * 		An exmaples is the root-to-leaf path 1->2->3 which represents the number 123.Find the total sum of 
 * 		all root-toleaf numbers.
 */


/**
 * Definition for a binary tree node.
 */

#include <iosteram>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
	public:
		int sumNumbers(TreeNode* root) {
			vector<int> arr;
			dfs(root, arr, sum);
			return sum;
		}

		int 
}
