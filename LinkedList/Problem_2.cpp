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
class CLinkedList
{
public:
	Node* head;
	Node* tail;

	CLinkedList()
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
			tail->next = head;
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
			tail->next = head;
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
			tail->next = head;
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
			do
			{
				cout << cur->data << " ";
				cur = cur->next;
			}while (cur != head);
			cout << endl;
		}
	}
	void deleteNode(int n)
	{
		Node* tmp = head;
		for (int i = 0; i < n-1; i++)
		{
			tmp = tmp->next;
		}
		Node* old = tmp->next;
		tmp->next = old->next;
		if (old == head)
		{
			head = head->next;
		}
		else if (old == tail)
		{
			tail = tmp;
		}
		delete old;
	}
};

int main()
{
	int M;
	cin >> M;

	for (int i = 0; i < M; i++)
	{
		CLinkedList clist;
		for (int j = 0; j < 10; j++)
		{
			int data;
			cin >> data;
			clist.addBack(data);
		}
		
		for (int i = 0; i < 3; i++)
		{
			string operation;
			cin >> operation;
			if (operation == "Delete")
			{
				int n;
				cin >> n;
				clist.deleteNode(n);
			}
		}
		clist.showList();
	}
	return 0;
}