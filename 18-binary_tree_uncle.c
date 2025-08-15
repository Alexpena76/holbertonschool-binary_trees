#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to the uncle node
 */

binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *parent;
	binary_tree_t *grandparent;

	if (node == NULL)
		return (NULL);

	if (node->parent == NULL)
		return (NULL);

	parent = node->parent;

	if (parent->parent == NULL)
		return (NULL);

	grandparent = parent->parent;

	if (grandparent->left == parent)
		return (grandparent->right);
	else
		return (grandparent->left);
}
