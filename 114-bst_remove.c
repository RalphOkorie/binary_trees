#include "binary_trees.h"
/**
 * min_finder - It finds the minimum root
 * @root: pointer to the tree
 * Return: the min number
 */

bst_t *min_finder(bst_t *root)
{
	while (root->left != NULL)
		root = root->left;
	return (root);
}

/**
 * bst_remove - It removes a node from a Binary Search Tree
 *
 * @root: pointer to the root node of the tree where you will remove a node
 * @value: value to remove in the tree
 * Return: pointer to the new root node of the tree
 * after removing the desired value
 */

bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tem, *parent;

	if (root == NULL)
		return (NULL);
	else if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL && root->right == NULL)
		{
			free(root);
			root = NULL;
		}
		else if (root->left == NULL)
		{
			tem = root;
			parent = root->parent;
			root = root->right;
			root->parent = parent;
			free(tem);
		}
		else if (root->right == NULL)
		{
			tem = root;
			parent = root->parent;
			root = root->left;
			root->parent = parent;
			free(tem);
		}
		else
		{
			tem = min_finder(root->right);
			root->n = tem->n;
			root->right = bst_remove(root->right, tem->n);
		}
	}
	return (root);
}
