#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node* next;
public:
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
	int getData()
	{
		return data;
	}
	void setData(int data)
	{
		this->data = data;
	}
	Node* getNext()
	{
		return next;
	}
	void setNext(Node* next)
	{
		this->next = next;
	}
};
class LinkedList
{
private:
	Node* head;
	Node* tail;
public:
	LinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}
	int front()
	{
		if (empty()) return -1;
		return head->getData();
	}
	int rear()
	{
		if (empty()) return -1;
		return tail->getData();
	}
	bool empty()
	{
		return head == nullptr;
	}
	void addFront(int data)
	{
		Node* tmp = new Node(data);
		if (empty())	tail = tmp;
		else tmp->setNext(head);
		head = tmp;
	}
	void addBack(int data)
	{
		Node* tmp = new Node(data);
		if (empty())	head = tmp;
		else	tail->setNext(tmp);
		tail = tmp;
	}
	int removeFront()
	{
		if (empty())
		{
			return-1;
		}
		int tmp = head->getData();
		head = head->getNext();
		return tmp;
	}
	int removeBack()
	{
		int old = tail->getData();
		if (empty())
		{
			return -1;
		}
		for (Node* tmp = head; tmp != tail; tmp = tmp->getNext())
		{
			if (tmp->getNext() == tail)
			{
				tail = tmp;
				tail->setNext(nullptr);
				delete tail->getNext();
				break;
			}
		}
		return old;
	}
	void print()
	{
		for (Node* tmp = head; tmp != nullptr; tmp = tmp->getNext())
		{
			cout << tmp->getData() << " ";
		}
		cout << endl;
	}
};

class Queue
{
private: 
	LinkedList* list; 
	int n;
	int N;
public:
	Queue(int N)
	{
		n = 0;
		this->N = N;
		list = new LinkedList();
	}
	bool full()
	{
		return n == N;
	}
	bool isEmpty()
	{
		return list->empty();
	}
	void enqueue(int data)
	{
		if (full())
		{
			cout << "Full" << endl;
		}
		else
		{
			list->addBack(data);
			n++;
		}
	}
	void dequeue()
	{
		if (isEmpty())
		{
			cout << "Empty" << endl;
		}
		else
		{
			cout << list->removeFront() << endl;
			n--;
		}
	}
	int size()
	{
		return n;
	}
	int front()
	{
		return list->front();
	}
	int rear()
	{
		return list->rear();
	}
};

int main()
{
	int S,N;
	cin >> S >> N;
	Queue* queue = new Queue(S);
	for (int i = 0; i < N; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "isEmpty")
		{
			cout << (int)(queue->isEmpty()) << endl;
		}
		else if (operation == "front")
		{
			if (queue->front() == -1)
			{
				cout << "Empty" << endl;
			}
			else
			{
				cout << queue->front() << endl;
			}
		}
		else if (operation == "rear")
		{
			if (queue->rear() == -1)
			{
				cout << "Empty" << endl;
			}
			else
			{
				cout << queue->rear() << endl;
			}
		}
		else if (operation == "size")
		{
			cout << queue->size() << endl;
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

	}
	return 0;
}