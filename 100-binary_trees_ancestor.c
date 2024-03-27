#include "binary_trees.h"

/**
 * binary_trees_ancestor - It finds the lowest common ancestor of two nodes.
 *
 * @first: A pointer to the first node.
 * @second: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, your function must return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *mama, *papa;

	if (!first || !second)
		return (NULL);
	if (first == second)
		return ((binary_tree_t *)first);

	mama = first->parent, papa = second->parent;
	if (first == papa || !mama || (!mama->parent && papa))
		return (binary_trees_ancestor(first, papa));
	else if (mama == second || !papa || (!papa->parent && mama))
		return (binary_trees_ancestor(mama, second));

	return (binary_trees_ancestor(mama, papa));
}
