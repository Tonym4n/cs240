#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>
#include <cassert>
using namespace std;

class Node
{
  public:
    int key;
    Node *left, *right;
    Node() : key(0), left(nullptr), right(nullptr) {}
    Node(int k, Node *l, Node *r) : key(k), left(l), right(r) {}
};

//set parent->key to be the biggest compared with all nodes in the left subtree;
//time complexity: O(logn) + O(logn);
//--O(logn)
void swapWithBiggestInLeftSubtree(Node *child, Node *parent, bool &swapped)
{
  if(child == nullptr)
    return;
  else if(child->key > parent->key)
  {
    swap(child->key, parent->key);
    swapped = true;
  }
  swapWithBiggestInLeftSubtree(child->left, parent, swapped);
  swapWithBiggestInLeftSubtree(child->right, parent, swapped);
}

//set parent->key to be the smallest compared with all nodes in the right subtree;
//time complexity: O(logn) + O(logn);
//--O(logn)
void swapWithSmallestInRightSubtree(Node *child, Node *parent, bool &swapped)
{
  if(child == nullptr)
    return;
  else if(child->key < parent->key)
  {
    swap(child->key, parent->key);
    swapped = true;
  }
  swapWithSmallestInRightSubtree(child->left, parent, swapped);
  swapWithSmallestInRightSubtree(child->right, parent, swapped);
}

//sort each individual node in the tree -- by performing swaps with keys > than itself in left subtree, and then with keys < than itself in right subtree; 
//this may lead to the key < a key in the leftsubtree hence the reason for the swap flag;
//time complexity: O(logn) + O(logn) + O(log(n-1)) + O(log(n-1)) 
//--O(logn)
void sortBTree(Node *node, bool &swapped)
{
  if(node == nullptr)
    return;
  
  sortBTree(node->left, swapped);
  sortBTree(node->right, swapped);

  swapWithBiggestInLeftSubtree(node->left, node, swapped);
  swapWithSmallestInRightSubtree(node->right, node, swapped);
}

//wrapper function;
//if a swap occurs, start again and sort from root;
//time complexity: n sorts at most
//--O(n)
void sortBinaryTree(Node *root)
{
  bool swapped;
  do
  {
    swapped = false;
    sortBTree(root, swapped);
  }
  while(swapped);
}

void inOrderTraversal(Node *node)
{
  if(node == nullptr)
    return;
  inOrderTraversal(node->left);
  cout << node->key << " ";
  inOrderTraversal(node->right);
}

//randomized insertions into binary tree;
void insert(Node *node, int key)
{
  assert(node != nullptr && "root cannot be nullptr");

  int child = rand() % 1;
  if(child == 0)
  {
    if(node->left == nullptr)
      node->left = new Node(key, nullptr, nullptr);
    else
      insert(node->left, key);
  }
  else if(child == 1)
  {
    if(node->right == nullptr)
      node->right = new Node(key, nullptr, nullptr);
    else
      insert(node->right, key);
  }
}

void clear(Node *node)
{
  if(node == nullptr)
    return;
  clear(node->left);
  clear(node->right);
  delete node;
}

int main() 
{
  srand(time(nullptr));
  int size = 100;
  Node *root = new Node(50, nullptr, nullptr);
  for(int i = 0, key; i < size; i++)
  {
    key = rand() % 1000;
    insert(root, key);
  }

  unsigned long long int startTime = time(nullptr);
  sortBinaryTree(root);
  cout << "TIME: " << (time(nullptr) - startTime) << endl;
  inOrderTraversal(root);
  clear(root);
}

//total time complexity: 
//--O(n) * O(logn) * O(logn) = O(nlog(^2)n)