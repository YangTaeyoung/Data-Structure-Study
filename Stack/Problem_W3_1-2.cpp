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
class Stack
{
private:
	LinkedList* stack;
	int n;
public:
	Stack()
	{
		stack = new LinkedList();
		n = 0;
	}
	bool empty()
	{
		return stack->empty();
	}
	int top()
	{
		if (empty())
		{
			return -1;
		}
		return stack->front();
	}
	void push(int data)
	{
		stack->addFront(data);
		n++;
	}
	int pop()
	{
		if (empty()) return -1;
		n--;
		return stack->removeFront();
	}
	int size()
	{
		return n;
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
			cout << (int)stack->empty() << endl;
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
			cout << stack->size() << endl;
		}
	}
}