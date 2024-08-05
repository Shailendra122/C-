/*
Treasure Hunt in Forest

Tim is on an adventure to find treasures in a magical forest. The forest is represented as a special kind of tree called a binary tree, where each node (a point in the tree) has a value representing the treasure amount.

Tim wants to find all the paths in the tree where the sum of the treasures equals a specific amount, called the targetAmount. The paths can start and end at any node, but Tim can only move downwards from parent nodes to child nodes.

Example 1:

Input:

root [3, 9, 5, -1, -4, null, 7, 2, null, null, 4, 1] targetAmount = 8

Output:

4

Explanation:

3

9

5

-1

-4

7

The paths that sum to 8 are:

9--1

3-5

3-9-4

7-1

Your Task:

Complete the provided pathSumFunction function that takes root of the binary tree as argument and returns number of paths between any two nodes in the given Binary Tree which have sum that add up to targetAmount

Constraints:

0 <<= n <= 1000 representing number of nodes.

-10^7 < data A= 10*7

-10^7 targetAmount <= 10^7

Input Format:

• The first line contains a space-separated integers representing the binary tree in level- order traversal.

The second line contains an integer targetAmount, representing the sum of the treasures.

Output Format:

The output is a single integer representing the number of paths that sum up to targetAmount.

Sample Input 1

395-1-4 null 7 2

8

null null 41

Sample Output 1

4

A

Sample Input 2

-4-4-3-335-3-4-5

8

Sample Output 2

0
*/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    int count = 0;
    int targetSum;

    void pathSumHelper(TreeNode* node, long long currentSum, unordered_map<long long, int>& prefixSums) {
        if (!node) return;

        currentSum += node->val;

        if (currentSum == targetSum) count++;
        count += prefixSums[currentSum - targetSum];

        prefixSums[currentSum]++;

        pathSumHelper(node->left, currentSum, prefixSums);
        pathSumHelper(node->right, currentSum, prefixSums);

        prefixSums[currentSum]--;
    }

public:
    int pathSum(TreeNode* root, int targetAmount) {
        targetSum = targetAmount;
        unordered_map<long long, int> prefixSums;
        pathSumHelper(root, 0, prefixSums);
        return count;
    }
};

TreeNode* buildTree(vector<string>& nodes) {
    if (nodes.empty() || nodes[0] == "null") return nullptr;

    TreeNode* root = new TreeNode(stoi(nodes[0]));
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < nodes.size()) {
        TreeNode* current = q.front();
        q.pop();

        if (i < nodes.size() && nodes[i] != "null") {
            current->left = new TreeNode(stoi(nodes[i]));
            q.push(current->left);
        }
        i++;

        if (i < nodes.size() && nodes[i] != "null") {
            current->right = new TreeNode(stoi(nodes[i]));
            q.push(current->right);
        }
        i++;
    }

    return root;
}

int main() {
    string input;
    getline(cin, input);

    vector<string> nodes;
    istringstream iss(input);
    string token;
    while (iss >> token) {
        nodes.push_back(token);
    }

    int targetAmount;
    cin >> targetAmount;

    TreeNode* root = buildTree(nodes);

    Solution solution;
    cout << solution.pathSum(root, targetAmount) << endl;

    return 0;
}
