#include "binary_trees.h"
/**
 * binary_tree_nodes - nodes of a binary tree
 * with at least one child
 * @tree: root of the tree
 * Return: size of the tree
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes  = 0;

	if (tree == NULL)
		return (0);
	nodes_binary_tree(tree, &nodes);

	return (nodes);
}
/**
 * nodes_binary_tree - nodes of a binary tree
 * @tree: node
 * @nodes: nodes
 * Return: nothing
 */
void nodes_binary_tree(const binary_tree_t *tree, size_t *nodes)
{
	if (tree != NULL)
	{
		if (tree->left != NULL || tree->right != NULL)
			(*nodes)++;
		if (tree->left != NULL)
			nodes_binary_tree(tree->left, nodes);
		if (tree->right != NULL)
			nodes_binary_tree(tree->right, nodes);
	}

}
