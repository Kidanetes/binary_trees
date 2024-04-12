#include "binary_trees.h"
/**
 * binary_tree_levelorder - levelorder transverse
 * @tree: tree
 * @func: function
 * Return: nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t size;
	binary_tree_t **tmp;
	size_t i = 0, j, k;
	int index = 0;

	if (func != NULL && tree != NULL)
	{
		size = binary_tree_size(tree);
		tmp = (binary_tree_t **)malloc(size * sizeof(binary_tree_t *));
		if (tmp == NULL)
			return;
		binary_tree_preorder_here(tree, tmp, &index);
		k = size;
		while (k > 0)
		{
			j = 0;
			while (j < size)
			{
				if (binary_tree_depth(tmp[j]) == i)
				{
					func(tmp[j]->n);
					k--;
				}
				j++;
			}
			i++;
		}

	}

}

/**
 * binary_tree_preorder - Pre-order traversal
 * @tree: root of the tree
 * @tmp: a pointer to point to preorderd nodes
 * @index: pointer to index
 * Return: nothing
 */
void binary_tree_preorder_here(const binary_tree_t *tree,
		binary_tree_t **tmp, int *index)
{
	binary_tree_t *left, *right;

	if (tree != NULL && *index < 7)
	{
		tmp[*index] =  malloc(sizeof(binary_tree_t *));
		tmp[*index] = (binary_tree_t *) tree;
		*index = *index + 1;
		left = tree->left;
		right = tree->right;
		binary_tree_preorder_here(left, tmp, index);
		binary_tree_preorder_here(right, tmp, index);
	}
}
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
/**
 * binary_tree_depth - depth of a node
 * @tree: a node whose depth will be measured
 * Return: depth of a node
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth = 0;

	while (tree != NULL && tree->parent != NULL)
	{
		depth++;
		tree = tree->parent;
	}
	return (depth);
}
