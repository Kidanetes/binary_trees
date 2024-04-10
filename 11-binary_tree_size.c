#include "binary_trees.h"
void size_binary_tree(const binary_tree_t *tree, size_t *size);
/**
 * binary_tree_size - size of binary tree
 * @tree: root of the tree
 * Return: size of the tree
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size  = 1;

	if (tree == NULL)
		return (0);
	size_binary_tree(tree, &size);

	return (size);
}
/**
 * size_binary_tree - size of binary tree
 * @tree: node
 * @size: size
 * Return: nothing
 */
void size_binary_tree(const binary_tree_t *tree, size_t *size)
{
	if (tree != NULL)
	{
		if (tree->left != NULL)
		{
			(*size)++;
			size_binary_tree(tree->left, size);
		}
		if (tree->right != NULL)
		{
			(*size)++;
			size_binary_tree(tree->right, size);
		}
	}

}

