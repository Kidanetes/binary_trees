#include "binary_trees.h"
/**
 * binary_tree_depth - depth of a node
 * @tree: a node whose depth will be measured
 * Return: depth of a node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
