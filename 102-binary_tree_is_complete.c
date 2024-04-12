#include "binary_trees.h"
/**
 * binary_tree_is_complete - is the binary tree complete
 * or not
 * @tree: root node
 * Return: 1(perfect) 0(otherwise)
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t height;
	int flag = 1, flag_2 = 1;

	if (tree == NULL)
		return (0);
	if (tree->left == NULL && tree->right == NULL)
		return (1);
	height = binary_tree_height(tree);
	is_complete(tree, &flag, &flag_2, height);
	if (flag == 0)
		return (0);
	return (1);
}

/**
 * is_complete - checks if the binary tree is
 * complete if tree != NULL
 * @tree: root node
 * @flag: flag
 * @flag_2: to check the leves are as far left
 * @height: height
 * Return: nothing
 */
void is_complete(const binary_tree_t *tree, int *flag,
		int *flag_2, size_t height)
{
	size_t depth;

	if (*flag == 0)
		return;
	depth = binary_tree_depth(tree);
	if (depth < height - 1)
	{
		if (tree->left == NULL || tree->right == NULL)
		{
			*flag = 0;
			return;
		}
	}


	if (depth == height - 1)
	{
		if (tree->left == NULL  && tree->right != NULL)
		{
			*flag = 0;
			return;
		}
		if (tree->left != NULL && *flag_2 == 0)
		{
			*flag = 0;
			return;
		}
		if ((tree->left != NULL && tree->right == NULL)
		  || tree->left == NULL)
			*flag_2 = 0;
	}

	if (tree->left != NULL)
		is_complete(tree->left, flag, flag_2, height);
	if (tree->right != NULL)
		is_complete(tree->right, flag, flag_2, height);
}


/**
 * binary_tree_height - height of binary tree
 * @tree: root of the tree
 * Return: height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_left = 0, height_right = 0;

	if (tree == NULL)
		return (0);

	if (tree->left != NULL)
		height_left = 1 + binary_tree_height(tree->left);
	if (tree->right != NULL)
		height_right = 1 + binary_tree_height(tree->right);
	if (height_left >= height_right)
		return (height_left);
	else
		return (height_right);
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
