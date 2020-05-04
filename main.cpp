#include <cstdlib>
#include <cstdio>
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
	FILE *outFile = fopen("results.txt", "w");

	printf("%s\t%s\t%s\t\t%s\t\n", "n", "binary_tree", "queue", "d_linked_list");
	fprintf(outFile, "%s\t%s\t%s\t\t%s\t\n", "n", "binary_tree", "queue", "d_linked_list");

	//compare the sorting times for binary trees, queues, and dlinkedlists;
	for(int n = 100; n < 10001; n *= 10)
	{
		bTree<int> bt;
		queue<int> q;
		DLinkedList<int> dlink;


		for(int i = 0, value; i < n; i++)
		{
			value = rand() % 1000;
			bt.insert(value);
			q.push(value);
			dlink.insert(value);
		}


		startTime = ::now();
		bt.sort();
		btTime = ::now() - startTime;

		startTime = ::now();
		sortQueue(q);
		qTime = ::now() - startTime;

		startTime = ::now();
		dlink.sort();
		dllTime = ::now() - startTime;


		printf("%d\t%llu\t\t%llu\t\t%llu\t\tms\n", n, btTime, qTime, dllTime);
		fprintf(outFile, "%d\t%llu\t\t%llu\t\t%llu\t\tms\n", n, btTime, qTime, dllTime);


		bt.clear();
		q = queue<int>();
		dlink.~DLinkedList();
	}
}
