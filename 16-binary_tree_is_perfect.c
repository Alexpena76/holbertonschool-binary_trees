#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise or if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int height;

	if (tree == NULL)
	{
		return (0);
	}

	height = (int)binary_tree_height(tree);

	return (is_perfect_recursive(tree, height, 0));
}

/**
 * is_perfect_recursive - Helper function to check if tree is perfect
 * @tree: Pointer to the current node being checked
 * @height: Expected height of a complete tree
 * @level: Current depth/level in the tree
 *
 * Return: 1 if the subtree rooted at this node is perfect, 0 otherwise
 */

int is_perfect_recursive(const binary_tree_t *tree, int height, int level)
{
	int left_perfect, right_perfect;

	if (tree == NULL)
	{
		return (1);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (level == height);
	}

	if ((tree->left == NULL && tree->right != NULL) || (tree->left != NULL && tree->right == NULL))
	{
		return (0);
	}

	left_perfect = is_perfect_recursive(tree->left, height, level + 1);
	right_perfect = is_perfect_recursive(tree->right, height, level + 1);

	return (left_perfect && right_perfect);
}
