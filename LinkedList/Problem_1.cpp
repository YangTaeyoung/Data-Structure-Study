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
	void removeFront()
	{
		Node* old = head;
		if (empty())
		{
			cout << -1 << endl;
		}
		else
		{
			head = old->next;
			cout << old->data << endl;
			delete old;
			if (empty())
			{
				tail = nullptr;
			}
		}
	}
	void removeBack()
	{
		Node* cur = head;
		if (empty())
		{
			cout << -1 << endl;
		}
		else
		{
			while (cur->next != tail)
			{
				cur = cur->next;
			}
			delete tail;
			tail = cur;
			if (empty())
			{
				head = nullptr;
			}
		}
	}
	void showList()
	{
		Node* cur = head;
		if (empty())
		{
			cout << -1 << endl;
		}
		else
		{
			while (cur != nullptr)
			{
				cout << cur->data << " ";
				cur = cur->next;
			}
			cout << endl;
		}
	}
};

int main()
{
	int M;
	cin >> M;
	LinkedList list;
	for (int i = 0; i < M; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "showList")
		{
			list.showList();
		}
		else if (operation == "empty")
		{
			cout << list.empty() << endl;
		}
		else if (operation == "addFront")
		{
			int data;
			cin >> data;
			list.addFront(data);
		}
		else if (operation == "addBack")
		{
			int data;
			cin >> data;
			list.addBack(data);
		}
		else if (operation == "removeFront")
		{
			list.removeFront();
		}
	}
	return 0;
}