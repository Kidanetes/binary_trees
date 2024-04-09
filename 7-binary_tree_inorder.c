#include "binary_trees.h"
/**
 * binary_tree_inorder - inorder traversal
 * @tree: root of the tree
 * @func: function to be called
 * Return: nothing
 */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *left, *right;

	if (tree != NULL && func != NULL)
	{
		left = tree->left;
		right = tree->right;
		binary_tree_inorder(left, func);
		func(tree->n);
		binary_tree_inorder(right, func);
	}
}


