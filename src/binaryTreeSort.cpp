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

	int child = rand() % 2;
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

//bubble sort for binary tree;
//Omega(n * logn * logn) | O(n * n * n)
template<typename T>
void bTree<T>::sort()
{
	bool swapped;
	do
	{
		swapped = false;
		sortBinaryTree(root, swapped);
	}while(swapped);
}

//sort the tree starting at node (top down sorting);
//swap node with biggest key in left subtree;
//swap node with smallest key in right subtree;
//repeat with left child, then right child;
//Omega(logn * logn) | O(n * n)
template<typename T>
void bTree<T>::sortBinaryTree(Node *node, bool& swapped)
{
	if(node == nullptr)
		return;

	swapWithBiggestInLeftSubtree(node, node->left, swapped);
	swapWithSmallestInRightSubtree(node, node->right, swapped);

	sortBinaryTree(node->left, swapped);
	sortBinaryTree(node->right, swapped);
}

//set parent->key to be the biggest compared with all nodes in the left subtree;
//Omega(logn) | O(n)
template<typename T>
void bTree<T>::swapWithBiggestInLeftSubtree(Node *parent, Node *child, bool& swapped)
{
	if(child == nullptr)
		return;
	else if(parent->key < child->key)
	{
		swap(parent->key, child->key);
		swapped = true;
	}

	swapWithBiggestInLeftSubtree(parent, child->left, swapped);
	swapWithBiggestInLeftSubtree(parent, child->right, swapped);
}

//set parent->key to be the smallest compared with all nodes in the right subtree;
//Omega(logn) | O(n)
template<typename T>
void bTree<T>::swapWithSmallestInRightSubtree(Node *parent, Node *child, bool& swapped)
{
	if(child == nullptr)
		return;
	else if(parent->key > child->key)
	{
		swap(parent->key, child->key);
		swapped = true;
	}

	swapWithSmallestInRightSubtree(parent, child->left, swapped);
	swapWithSmallestInRightSubtree(parent, child->right, swapped);
}
//----------------------------------------------------------------------------------

//instantiate the template class with specific types;
template class bTree<int>;
template class bTree<float>;
template class bTree<double>;
template class bTree<char>;
template class bTree<string>;