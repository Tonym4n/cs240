#include "queueSort.hh"

void sortQueue(std::queue<int> &q) 
{ 
	int n = q.size();
    for(int i = 0; i < n; i++) 
    {
    	int smallestIndex = 0; 
    	int smallestValue = q.front();
    	int frontValue;

    	//get index for smallestValue in queue while retaining its state
    	for(int j = 0; j < n; j++) 
    	{
    	    frontValue = q.front(); 
    	    q.pop();

    	    //if value in front of queue is < smallestValue AND
    	    //j is not in the sorted portion of the queue
    	    if(frontValue <= smallestValue && j < n - i) 
    	    { 
    	        smallestIndex = j; 
    	        smallestValue = frontValue;
    	    } 

    	    q.push(frontValue);
    	}

    	//traverse the whole queue again enqueuing and dequeuing all 
    	//elements except for the smallestValue
    	//enqueue smallestValue at the end of the sorted portion of queue
    	for(int j = 0; j < n; j++) 
    	{ 
    	    frontValue = q.front();
    	    q.pop();

    	    if(j == smallestIndex)
    	    	continue;
			q.push(frontValue);
    	} 
    	q.push(smallestValue); 
    }
}