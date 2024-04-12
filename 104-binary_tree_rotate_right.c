#include "binary_trees.h"
/**
 * binary_tree_rotate_right - rotates
 * a binary tree to the right
 * @tree: root
 * Return: the new root
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *tmp1;

	if (tree == NULL)
		return (NULL);
	if (tree->left == NULL)
		return (tree);
	tmp1 = tree->left;
	tree->parent = tmp1;
	tree->left = tmp1->right;
	tmp1->right = tree;
	tmp1->parent = NULL;
	return (tmp1);
}

