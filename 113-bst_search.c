#include "binary_trees.h"
/**
 * bst_search - search for a value in BST
 * @tree: root node
 * @value: vlaue to be searched
 * Return: node(if node->n == value or NULL
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	bst_t *node = (bst_t *)tree;

	while (1)
	{
		if (node == NULL)
			return (NULL);
		if (node->n == value)
			return (node);
		else if (node->n < value)
			node = node->right;
		else
			node = node->left;
	}
}

