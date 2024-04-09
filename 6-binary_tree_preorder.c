#include "binary_trees.h"
/**
 * binary_tree_preorder - Pre-order traversal
 * @tree: root of the tree
 * @func: function to be called
 */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *left, *right;

	if (tree != NULL && func != NULL)
	{
		left = tree->left;
		right = tree->right;
		func(tree->n);
		binary_tree_preorder(left, func);
		binary_tree_preorder(right, func);
	}
}


