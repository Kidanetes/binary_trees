#include "binary_trees.h"
/**
 * binary_trees_ancestor - return lowest common ancestor of
 * two nodes
 * @first: first node
 * @second: second node
 * Return: pointer to lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *tmp1, *tmp2, *tmp3;

	if (first == NULL || second == NULL)
		return (NULL);
	tmp1 = (binary_tree_t *)first;
	tmp2 = (binary_tree_t *)second;

	while (tmp1 != NULL)
	{
		tmp3 = tmp2;
		while (tmp3 != NULL)
		{
			if (tmp1 == tmp3)
				return (tmp1);
			if (tmp1 == tmp3->parent)
				return (tmp1);
			if (tmp3 == tmp1->parent)
				return (tmp3);
			tmp3 = tmp3->parent;
		}
		tmp1 = tmp1->parent;
	}
	return (NULL);
}
