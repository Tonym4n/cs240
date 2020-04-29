#include <cstdlib>
#include <chrono>

#include "binaryTreeSort.hh"

using namespace std;

//return # of milliseconds since epoch;
static unsigned long long int now() 
{
  return chrono::duration_cast<chrono::milliseconds>
  	(chrono::system_clock::now().time_since_epoch()).count();
}

int main() 
{
  srand(time(nullptr));
  unsigned long long int startTime, endTime;

  //compare the sorting times for binary trees, queues, and dlinkedlists;
  //for n = 100, 1000, 10000, and 100000;
  for(int n = 100; n < 100001; n *= 10)
  {
  	Node *root = new Node(0);
  	for(int i = 0, key; i < n; i++)
  	{
  		key = rand() % 1000;
  		insert(root, key);
  	}





  	startTime = ::now();
  	sortBinaryTree(root);
  	endTime = ::now() - startTime;
  	cout << "\nbinary tree sort time for n(" << n << "): " << endTime << "ms\n";

  	clear(root);
  }
}
