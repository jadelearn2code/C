#include <unistd.h>

typedef struct s_btree t_btree;

struct s_btree
{
	t_btree		*left;
	t_btree		*right;
	void		*item;
};

/**
 * btree_len - Calculates the total number of nodes in a binary tree.
 * @root: A pointer to the root of the binary tree.
 *
 * This function uses a recursive approach to calculate the total number of nodes in a binary tree.
 * The size of the tree is the size of the left subtree plus 1 (for the root node) plus the size of the right subtree.
 * If the tree is empty (i.e., the root is NULL), the function returns 0.
 *
 * The function has a time complexity of O(n), where n is the number of nodes in the tree,
 * as it visits each node exactly once. The space complexity is O(h), where h is the height of the tree,
 * due to the recursive call stack.
 */
size_t btree_len(t_btree *root) {
	if (!root) {
		return 0;  // If the tree is empty, return 0
  }

	// Recursively calculate the size of the left and right subtrees, and add 1 for the root node
	return btree_len(root->left) + 1 + btree_len(root->right);
}
