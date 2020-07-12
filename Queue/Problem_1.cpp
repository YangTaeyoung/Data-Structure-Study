#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		next = nullptr;
	}
};

class LinkedList
{
public:
	Node* head;
	Node* tail;
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
	~LinkedList()
	{
		delete head;
		delete tail;
	}
	bool empty()
	{
		return head == nullptr;
	}
	int front()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return head->data;
		}
	}
	int rear()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return tail->data;
		}
	}
	void addBack(int data)
	{
		Node* tmp = new Node(data);
		if (empty())
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tail->next = tmp;
			tail = tmp;
		}
	}
	int removeFront()
	{
		Node* old = head;
		int value = old->data;
		
		if (empty())
		{
			return -1;
		}
		else
		{
			head = old->next;
			delete old;
			if (empty())
			{
				tail = nullptr;
			}
			return value;
		}
	}
};
class Queue
{
public:
	int size;
	int n;
	LinkedList* list;

	Queue(int size)
	{
		n = 0;
		this->size = size;
		list = new LinkedList();
	}
	~Queue()
	{
		delete list;
	}
	bool isEmpty()
	{
		return list->empty();
	}
	void enqueue(int data)
	{
		if (n == size)
			cout << "Full" << endl;
		else
		{
			list->addBack(data);
			n++;
		}
	}
	void dequeue()
	{
		if (isEmpty())
			cout << "Empty" << endl;
		else
		{
			cout << list->removeFront() << endl;
			n--;
		}
	}
	int getSize()
	{
		return n;
	}
	void front()
	{
		if (isEmpty())
			cout << "Empty" << endl;
		else
			cout << list->front() << endl;
	}
	void rear()
	{
		if (isEmpty())
			cout << "Empty" << endl;
		else
			cout << list->rear() << endl;
	}
};

int main()
{
	int size;
	cin >> size;
	Queue* queue = new Queue(size);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "isEmpty")
		{
			cout << queue->isEmpty()<< endl;
		}
		else if (operation == "size")
		{
			cout << queue->getSize() << endl;
		}
		else if (operation == "enqueue")
		{
			int data;
			cin >> data;
			queue->enqueue(data);
		}
		else if (operation == "dequeue")
		{
			queue->dequeue();
		}
		else if (operation == "front")
		{
			queue->front();
		}
		else if (operation == "rear")
		{
			queue->rear();
		}
	}
	delete queue;
	return 0;
}