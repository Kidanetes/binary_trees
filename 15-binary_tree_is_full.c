#include "binary_trees.h"
/**
 * binary_tree_is_full - checks if the
 * binary tree is full or not
 * @tree: root bo binary tree
 * Return: 1(full) 0(otherwise)
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	int flag = 1;

	if (tree == NULL)
		return (0);
	is_full(tree, &flag);
	if (flag == 0)
		return (0);
	else
		return (1);
}
/**
 * is_full - checks if the binary tree is
 * full if tree != NULL
 * @tree: root node
 * @flag: flag
 * Return: nothing
 */
void is_full(const binary_tree_t *tree, int *flag)
{
	if (*flag == 0)
		return;
	if (tree->left == NULL && tree->right != NULL)
	{
		*flag = 0;
		return;
	}
	if (tree->left != NULL && tree->right == NULL)
	{
		*flag = 0;
		return;
	}
	if (tree->left != NULL)
		is_full(tree->left, flag);
	if (tree->right != NULL)
		is_full(tree->right, flag);
}
