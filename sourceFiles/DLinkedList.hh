#ifndef DLINKED_LIST_HH_
#define DLINKED_LIST_HH_

#include <iostream>
#include <cassert>
template<typename T>
class DLinkedList
{
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
        Node(T val): data(val), next(nullptr), prev(nullptr) {}
    };
    Node *head, *tail;

    public:
        DLinkedList(): head(nullptr), tail(nullptr){}

        ~DLinkedList()
        {
            Node *tmp = nullptr;
            while (head)
            {
               tmp = head;
               head = head->next;
               delete tmp;
            }
            head = nullptr;
        }

        DLinkedList(const DLinkedList &copy) = delete;
        DLinkedList& operator=(DLinkedList const&) = delete;

        void insert(T val)
        {
	    Node *node = new Node(val);
            if (head == nullptr)
            {
               head = node;
               tail = node;
            }
            else
            {
               node->next = head;
               head = node;
               node->next->prev = node;
            }
        }

        void sort() //BubbleSort
        {
	    bool swapped = false;
	    Node *tempHead = nullptr;
	    Node *temp = nullptr;

	    assert(head != nullptr && "Cannot sort empty List");
	    //forcing the first loop
	    do
	    {
		swapped = false;
		tempHead = head;

		while(tempHead->next != temp)
		{
			if(tempHead->data > tempHead->next->data)
			{
				std::swap(tempHead->data, tempHead->next->data);
				swapped = true;
			}
			tempHead = tempHead->next;
		}
		temp = tempHead;
	    }
	    while(swapped);
        }

     template <typename U>
     friend std::ostream & operator<<(std::ostream & os, const DLinkedList<U> & dll){
      dll.display(os);
      return os;
     }

      void display(std::ostream& out = std::cout) const
       {
            Node *node = head;
            while(node != nullptr)
            {
                out << node->data << " ";
                node = node->next;
            }
        }
};


#endif //ifndef DLINKED_LIST_HH_
