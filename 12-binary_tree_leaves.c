#include "binary_trees.h"
/**
 * binary_tree_leaves - how man leaves are in the
 * binary tree
 * @tree: root of the tree
 * Return: leaves of the tree
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves  = 0;

	if (tree == NULL)
		return (0);
	leaves_binary_tree(tree, &leaves);

	return (leaves);
}
/**
 * leaves_binary_tree - leaves of a binary tree
 * @tree: node
 * @leaves: leaves
 * Return: nothing
 */
void leaves_binary_tree(const binary_tree_t *tree, size_t *leaves)
{
	if (tree != NULL)
	{
		if (tree->left != NULL)
			leaves_binary_tree(tree->left, leaves);
		if (tree->right != NULL)
			leaves_binary_tree(tree->right, leaves);
		if (tree->left == NULL && tree->right == NULL)
			(*leaves)++;
	}
}

