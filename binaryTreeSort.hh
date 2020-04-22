#ifndef binaryTreeSort_hh
#define binaryTreeSort_hh
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;

class Node
{
  public:
    int key;
    Node *left, *right;
    Node() : key(0), left(nullptr), right(nullptr) {}
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
    Node(int k, Node *l, Node *r) : key(k), left(l), right(r) {}
};

void inOrderTraversal(Node *node);
void insert(Node *node, int key);
void clear(Node *node);

void sortBinaryTree(Node *root);
void swapWithBiggestInLeftSubtree(Node *parent, Node *child);
void swapWithSmallestInRightSubtree(Node *parent, Node *child);

#endif
