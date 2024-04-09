#include "binary_trees.h"
/**
 * binary_tree_insert_right - inserts a right child node
 * @parent: parent node
 * @value: value of a node
 * Return: new node
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *node,  *tmp;

	if (parent == NULL)
		return (NULL);
	node = malloc(sizeof(binary_tree_t));
	if (node == NULL)
		return (NULL);
	node->n = value;
	node->left = NULL;
	if (parent->right == NULL)
	{
		parent->right = node;
		node->right = NULL;
	}
	else
	{
		tmp = parent->right;
		parent->right = node;
		node->right = tmp;
		tmp->parent = node;
	}
	node->parent = parent;
	return (node);
}
