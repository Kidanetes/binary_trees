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
	if (tree->left == NULL)
		height_left = 0;
	else
		height_left = 1 + binary_tree_height(tree->left);
	if (tree->right == NULL)
		height_right = 0;
	else
		height_right = 1 + binary_tree_height(tree->right);
	return (height_left - height_right);

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
