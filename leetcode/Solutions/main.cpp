#include "common.h"

#include "Binary Tree Level Order Traversal II.h"

extern int strStr(const char *src, const char *pattern);

int main(int argc, char *argv[]) {
	Solution_BinaryTreeLevelOrderTraversalII s;
	TreeNode n1(3), n2(9), n3(20), n4(15), n5(7);
	n1.left = &n2;
	n1.right = &n3;
	n3.left = &n4;
	n3.right = &n5;
	vector<vector<int>> tmp = s.levelOrderBottom(&n1);
	return 0;
}