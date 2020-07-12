#include<iostream>
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
	int front()
	{
		return head->data;
	}
	bool empty()
	{
		return head == nullptr;
	}
	void addFront(int data)
	{
		Node* tmp = new Node(data);
		if (empty())
		{
			head = tmp;
			tail = tmp;
		}
		else
		{
			tmp->next = head;
			head = tmp;
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
				tail = nullptr;
			return value;
		}
	}
};
class Stack
{
public:
	LinkedList* list;
	int size;

	Stack()
	{
		list = new LinkedList();
		size = 0;
	}
	~Stack()
	{
		delete list;
	}
	void push(int data)
	{
		list->addFront(data);
		size++;
	}
	bool empty()
	{
		return list->empty();
	}
	int pop()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			size--;
			return list->removeFront();
		}
	}
	int top()
	{
		if (empty())
		{
			return -1;
		}
		else
		{
			return list->front();
		}
	}
	int getSize()
	{
		return size;
	}
};

int main()
{
	int N;
	cin >> N;
	Stack* stack = new Stack();
	for (int i = 0; i < N; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "empty")
		{
			cout << stack->empty() << endl;
		}
		else if (operation == "top")
		{
			cout << stack->top() << endl;
		}
		else if (operation == "push")
		{
			int data;
			cin >> data;
			stack->push(data);
		}
		else if (operation == "pop")
		{
			cout << stack->pop() << endl;
		}
		else if (operation == "size")
		{
			cout << stack->getSize() << endl;
		}
	}
	delete stack;
	return 0;
}