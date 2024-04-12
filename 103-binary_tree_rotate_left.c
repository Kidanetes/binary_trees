#include "binary_trees.h"
/**
 * binary_tree_rotate_left - rotates
 * a binary tree to the left
 * @tree: root
 * Return: the new root
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *tmp1;

	if (tree == NULL)
		return (NULL);
	if (tree->right == NULL)
		return (tree);
	tmp1 = tree->right;
	tree->parent = tmp1;
	tree->right = tmp1->left;
	tmp1->left = tree;
	tmp1->parent = NULL;
	return (tmp1);
}

