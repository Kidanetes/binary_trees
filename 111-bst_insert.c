#include "binary_trees.h"
/**
 * bst_insert - insert into BST
 * @tree: double pointer to root
 * @value: a value of a inserted node
 * Return: pointer to inserted node
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *root = *tree;

	if (tree == NULL)
		return (NULL);

	if (root == NULL)
	{
		root = binary_tree_node(NULL, value);
		*tree = root;
		return (root);
	}
	while (1)
	{
		if (root->n > value)
		{
			if (root->left == NULL)
			{
				root->left = binary_tree_node(root, value);
				return (root->left);
			}
			else
				root = root->left;
		}
		else if (root->n < value)
		{
			if (root->right == NULL)
			{
				root->right = binary_tree_node(root, value);
				return (root->right);
			}
			else
				root = root->right;
		}
		else
		{
			return (NULL);
		}
	}
	return (NULL);
}
