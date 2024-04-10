#include "binary_trees.h"
/**
 * binary_tree_sibling - find the sibling of a node
 * @node: node
 * Return: pointer to the sibling of a node
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *tmp;

	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	tmp = node->parent;
	if (tmp->left == NULL || tmp->right == NULL)
		return (NULL);
	if (tmp->left == node)
		return (tmp->right);
	return (tmp->left);
}
