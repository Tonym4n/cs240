#include <ctime>
#include <cstdlib>

#include "binaryTreeSort.hh"

using namespace std;

int main() 
{
  srand(time(nullptr));
  unsigned long long int startTime, endTime;
  int size = 100;

  Node *root = new Node(50, nullptr, nullptr);
  for(int i = 0, key; i < size; i++)
  {
    key = rand() % 1000;
    insert(root, key);
  }

  cout << "Binary tree before sorting (inorder traversal): " << endl;
  inOrderTraversal(root);
  cout << endl;

  startTime = time(nullptr);
  sortBinaryTree(root);
  endTime = time(nullptr) - startTime;
  cout << "TIME TO SORT BINARY TREE: " << endTime << " seconds" << endl;

  cout << "Binary tree after sorting (inorder traversal): " << endl;
  inOrderTraversal(root);
  cout << endl;
  clear(root);
}
