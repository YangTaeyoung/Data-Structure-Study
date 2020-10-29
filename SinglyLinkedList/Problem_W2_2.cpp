#include<iostream>
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
int main()
{
	int N;
	cin >> N;
	LinkedList* list = new LinkedList();
	for (int i = 0; i < N; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "addFront")
		{
			int data;
			cin >> data;
			list->addFront(data);
		}
		else if (operation == "addBack")
		{
			int data;
			cin >> data;
			list->addBack(data);
		}
		else if (operation == "front")
		{
			cout << list->front() << endl;
		}
		else if (operation == "empty")
		{
			cout << (int)list->empty() << endl;
		}
		else if (operation == "removeFront")
		{
			cout << list->removeFront() << endl;
		}
		else if (operation == "removeBack")
		{
			cout << list->removeBack() << endl;
		}
		else if (operation == "print")
		{
			list->print();
		}
	}
	delete list;
	return 0;
}