#include "binaryTreeSort.hh"

//prints out the binary tree in sorted order;
void inOrderTraversal(Node *node)
{
  if(node == nullptr)
    return;
  inOrderTraversal(node->left);
  cout << node->key << " ";
  inOrderTraversal(node->right);
}

//randomized insertions into binary tree;
//results in (maybe) unbalanced and/or unsorted tree;
void insert(Node *node, int key)
{
  assert(node != nullptr && "root cannot be nullptr");

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

//free up all allocated memory in the binary tree;
void clear(Node *node)
{
  if(node == nullptr)
    return;
  clear(node->left);
  clear(node->right);
  delete node;
}

//----------------------------------------------------------------------------------
//total time complexity for sortBinaryTree(): 
//O(logn * logn)

//sort the tree starting at node (top down sorting);
//swap node with biggest key in left subtree;
//swap node with smallest key in right subtree;
//repeat with left child, then right child;
//O(log(n-1)) + O(log(n-1)) + O(logn) + O(logn) = O(logn)
void sortBinaryTree(Node *node)
{
  if(node == nullptr)
    return;
  
  swapWithBiggestInLeftSubtree(node, node->left);
  swapWithSmallestInRightSubtree(node, node->right);

  sortBinaryTree(node->left);
  sortBinaryTree(node->right);
}

//set parent->key to be the biggest compared with all nodes in the left subtree;
//time complexity: O(log(n-1)) + O(log(n-1)) = O(logn)
void swapWithBiggestInLeftSubtree(Node *parent, Node *child)
{
  if(child == nullptr)
    return;
  else if(parent->key < child->key)
    swap(parent->key, child->key);

  swapWithBiggestInLeftSubtree(parent, child->left);
  swapWithBiggestInLeftSubtree(parent, child->right);
}

//set parent->key to be the smallest compared with all nodes in the right subtree;
//time complexity: O(log(n-1)) + O(log(n-1)) = O(logn)
void swapWithSmallestInRightSubtree(Node *parent, Node *child)
{
  if(child == nullptr)
    return;
  else if(parent->key > child->key)
    swap(parent->key, child->key);

  swapWithSmallestInRightSubtree(parent, child->left);
  swapWithSmallestInRightSubtree(parent, child->right);
}
//----------------------------------------------------------------------------------
