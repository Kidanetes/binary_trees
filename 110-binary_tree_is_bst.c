#include "binary_trees.h"
/**
 * binary_tree_is_bst - checks if the binary tree is
 * binary search tree
 * @tree: root
 * Return: 1(BST) 0(oterwise)
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	int flag = 1;

	if (tree == NULL)
		return (0);
	is_bst(tree, &flag);
	if (flag == 0)
		return (0);
	return (1);
}
/**
 * is_bst - checks if the binary tree is
 * binary search tree
 * @tree: root
 * @flag: flag
 * Return: nothing
 */
void is_bst(const binary_tree_t *tree, int *flag)
{
	if (*flag == 0)
		return;
	if (tree->left != NULL)
	{
		if (tree->left->n >= tree->n)
		{
			*flag = 0;
			return;
		}
		more_bst(tree->left, flag);
	}
	if (tree->right != NULL)
	{
		if (tree->right->n <= tree->n)
		{
			*flag = 0;
			return;
		}
		more_bst(tree->right, flag);
	}
	if (tree->left != NULL)
		is_bst(tree->left, flag);
	if (tree->right != NULL)
		is_bst(tree->right, flag);
}
/**
 * more_bst - checks if the binary tree is
 * binary search tree
 * @tree: root
 * @flag: flag
 * Return: nothing
 */
void more_bst(const binary_tree_t *tree, int *flag)
{
	binary_tree_t *tmp1 = tmp1 = (binary_tree_t *)tree, *tmp2 = tree->parent;

	if (tmp2 == NULL)
		return;
	while (tmp2 != NULL)
	{
		if (tmp2->left == tmp1 && tree->n >= tmp2->n)
		{
			*flag = 0;
			return;
		}
		if (tmp2->right == tmp1 && tree->n <= tmp2->n)
		{
			*flag = 0;
			return;
		}
		tmp1 = tmp2;
		tmp2 = tmp2->parent;
	}
}
