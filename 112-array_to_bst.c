#include "binary_trees.h"
/**
 * array_to_bst - create BST from array
 * @array: array from which a BST will
 * be created
 * @size: size of the array
 * Return: pointer to root node
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *tree = NULL;
	size_t i;

	if (size == 0)
		return (NULL);
	tree = bst_insert(&tree, array[0]);
	for (i = 1; i < size; i++)
		bst_insert(&tree, array[i]);
	return (tree);
}



