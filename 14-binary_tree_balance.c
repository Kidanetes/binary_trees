#include "binary_trees.h"
/**
 * binary_tree_balance - balance between left childs and right childs
 * @tree: root of the binary tree
 *
 * Return: balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);
	if (tree->left != NULL)
		height_left = 1 + binary_tree_balance(tree->left);
	if (tree->right != NULL)
		height_right = 1 + binary_tree_balance(tree->right);
	return (height_left - height_right);

}

