#include "binary_trees.h"
/**
 * binary_tree_insert_left - inserts a left child node
 * @parent: parent node
 * @value: value of a node
 * Return: new node
 */

binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *node,  *tmp;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->right = NULL;
	if (parent->left == NULL)
	{
		parent->left = node;
		node->left = NULL;
	}
	else
	{
		tmp = parent->left;
		parent->left = node;
		node->left = tmp;
		tmp->parent = node;
	}
	node->parent = parent;
	return (node);
}
