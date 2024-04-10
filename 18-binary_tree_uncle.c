#include "binary_trees.h"
/**
 * binary_tree_uncle - find the uncle of a node
 * @node: node
 * Return: pointer to the uncle of a node
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *tmp;

	if (node == NULL)
		return (NULL);
	if (node->parent == NULL)
		return (NULL);
	if (node->parent->parent == NULL)
		return (NULL);
	tmp = node->parent->parent;
	if (tmp->left == NULL || tmp->right == NULL)
		return (NULL);
	if (tmp->left == node->parent)
		return (tmp->right);
	return (tmp->left);
}
