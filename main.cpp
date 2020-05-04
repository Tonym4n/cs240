#include <cstdlib>
#include <chrono>

#include "binaryTreeSort.hh"
#include "queueSort.hh"
#include "DLinkedList.hh"
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
  unsigned long long int startTime, btTime, qTime, dllTime;

  printf("%s\t%s\t%s\t\t%s\t\n", "n", "binary_tree", "queue", "d_linked_list");

  //compare the sorting times for binary trees, queues, and dlinkedlists;
  //for n = 100, 1000, 10000, and 100000;
  for(int n = 100; n < 10001; n *= 10)
  {
  	Node *root = new Node(0);
	queue<int> q;
	DLinkedList<int> dlink;
	//initialize dlinkedlist;


  	for(int i = 0, value; i < n; i++)
  	{
  		value = rand() % 1000;
  		insert(root, value);
		q.push(value);
		dlink.insert(value);
		//insert into dlinkedlist;
  	}
	startTime = ::now();
  	sortBinaryTree(root);
  	btTime = ::now() - startTime;

  	startTime = ::now();
  	sortQueue(q);
  	qTime = ::now() - startTime;

	startTime = ::now();
	dlink.sort();
	dllTime = ::now() - startTime;

	printf("%d\t%llu\t\t%llu\t\t%llu\t\tms\n", n, btTime, qTime, dllTime);
	clear(root);
	q = queue<int>();
  }
}
