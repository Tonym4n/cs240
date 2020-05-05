#include "binaryTreeSort.hh"

//free up all allocated memory in the binary tree;
template<typename T>
void bTree<T>::clear(Node *node)
{
	if(node == nullptr)
		return;
	clear(node->left);
	clear(node->right);
	delete node;
}

//randomized insertions into binary tree;
//results in (maybe) unbalanced and/or unsorted tree;
template<typename T>
void bTree<T>::insert(Node *node, T key)
{
	assert(node != nullptr && "node cannot be nullptr");

	int child = rand() % 1;
	if(child == 0)
	{
		if(node->left == nullptr)
			node->left = new Node(key);
		else
			insert(node->left, key);
	}
	else if(child == 1)
	{
		if(node->right == nullptr)
			node->right = new Node(key);
		else
			insert(node->right, key);
	}
}

//prints out the binary tree in sorted order;
template<typename T>
void bTree<T>::inOrderTraversal(Node *node)
{
	if(node == nullptr)
		return;
	inOrderTraversal(node->left);
	cout << node->key << " ";
	inOrderTraversal(node->right);
}

//----------------------------------------------------------------------------------
//total time complexity for sortBinaryTree(): 
//Omega(logn * logn) | O(n^2)

//sort the tree starting at node (top down sorting);
//swap node with biggest key in left subtree;
//swap node with smallest key in right subtree;
//repeat with left child, then right child;
//Omega(logn) * Omega(logn) | O(n) * O(n)
template<typename T>
void bTree<T>::sortBinaryTree(Node *node)
{
	if(node == nullptr)
		return;

	swapWithBiggestInLeftSubtree(node, node->left);
	swapWithSmallestInRightSubtree(node, node->right);

	sortBinaryTree(node->left);
	sortBinaryTree(node->right);
}

//set parent->key to be the biggest compared with all nodes in the left subtree;
//Omega(logn) | O(n)
template<typename T>
void bTree<T>::swapWithBiggestInLeftSubtree(Node *parent, Node *child)
{
	if(child == nullptr)
		return;
	else if(parent->key < child->key)
		swap(parent->key, child->key);

	swapWithBiggestInLeftSubtree(parent, child->left);
	swapWithBiggestInLeftSubtree(parent, child->right);
}

//set parent->key to be the smallest compared with all nodes in the right subtree;
//Omega(logn) | O(n)
template<typename T>
void bTree<T>::swapWithSmallestInRightSubtree(Node *parent, Node *child)
{
	if(child == nullptr)
		return;
	else if(parent->key > child->key)
		swap(parent->key, child->key);

	swapWithSmallestInRightSubtree(parent, child->left);
	swapWithSmallestInRightSubtree(parent, child->right);
}
//----------------------------------------------------------------------------------

//instantiate the template class with specific types;
template class bTree<int>;
template class bTree<float>;
template class bTree<double>;
template class bTree<char>;
template class bTree<string>;
