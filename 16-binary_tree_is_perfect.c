#include "binary_trees.h"
/**
 * binary_tree_is_perfect - is the binary tree perfect
 * or not
 * @tree: root node
 * Return: 1(perfect) 0(otherwise)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t depth1 = 0, depth2 = 0;
	int flag = 1;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	is_perfect(tree, &flag, &depth1, &depth2);
	if (flag == 0)
		return (0);
	return (1);
}
/**
 * is_perfect - checks if the binary tree is
 * perfect if tree != NULL
 * @tree: root node
 * @flag: flag
 * @depth1: depth of a leave
 * @depth2: depth of anohter leave
 * Return: nothing
 */
void is_perfect(const binary_tree_t *tree, int *flag,
		size_t *depth1, size_t *depth2)
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
	if (tree->left == NULL && tree->right == NULL)
	{
		if (*depth1 == 0)
			*depth1 = binary_tree_depth(tree);
		else
			*depth2 = binary_tree_depth(tree);
		if (*depth2 != 0)
		{
			if (*depth1 != *depth2)
			{
				*flag = 0;
				return;
			}
		}
	}
	if (tree->left != NULL)
		is_perfect(tree->left, flag, depth1, depth2);
	if (tree->right != NULL)
		is_perfect(tree->right, flag, depth1, depth2);
}
/**
 * binary_tree_depth - depth of a node
 * @tree: a node whose depth will be measured
 * Return: depth of a node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL && tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
