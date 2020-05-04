#ifndef binaryTreeSort_hh
#define binaryTreeSort_hh
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

template<typename T>
class bTree
{
private:
	class Node
	{
	public:
		T key;
		Node *left, *right;
		Node() : key(0), left(nullptr), right(nullptr) {}
		Node(T k) : key(k), left(nullptr), right(nullptr) {}
		Node(T k, Node *l, Node *r) : key(k), left(l), right(r) {}
	};

	Node *root;

public:
	bTree() : root(new Node()) {}
	bTree(T k) : root(new Node(k)) {}
	bTree(T k, Node *l, Node *r) : root(new Node(k, l, r)) {}

	void clear() {clear(root);}
	void insert(T key) {insert(root, key);};
	void print() {inOrderTraversal(root);}
	void sort() {sortBinaryTree(root);}

protected:
	void clear(Node *node);
	void insert(Node *node, T key);
	void inOrderTraversal(Node *node);
	void sortBinaryTree(Node *node);
	void swapWithBiggestInLeftSubtree(Node *parent, Node *child);
	void swapWithSmallestInRightSubtree(Node *parent, Node *child);
};

#endif