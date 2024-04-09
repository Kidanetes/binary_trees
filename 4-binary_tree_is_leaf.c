#include "binary_trees.h"
/**
 * binary_tree_is_leaf - checks whether a node
 * has child or not
 * @node: node
 * Return: 1(leaf node) 0(otherwise)
 */
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node == NULL)
		return (0);
	if (node->left == NULL && node->right == NULL)
		return (1);
	return (0);
}
