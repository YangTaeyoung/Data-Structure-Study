#include <iostream>
#include <cmath>
using namespace std;
class DoublyLinkedList
{
private:
	struct Node
	{
		int data;
		Node* next;
		Node* prev;
	};
	class Iterator
	{
		Node* v;
		Iterator(Node* v)
		{
			this->v = v;
		}

		bool operator!=(Iterator& p)
		{
			return p.v != v;
		}
		bool operator==(Iterator& p)
		{
			return p.v == v;
		}
		Iterator& operator++()
		{
			v = v->next;
			return *this;
		}
		Iterator& operator--()
		{
			v = v->prev;
			return *this;
		}
		Node* operator*()
		{
			return this->v;
		}
		friend class DoublyLinkedList;
	};
	Node* header;
	Node* trailer;
public:
	DoublyLinkedList()
	{
		header = new Node;
		trailer = new Node;
		header->next = trailer;
		trailer->prev = header;
	}
	~DoublyLinkedList()
	{
		delete header;
		delete trailer;
	}
	Iterator& begin()
	{
		Iterator* p = new Iterator(header->next);
		return *p;
	}
	Iterator& end()
	{
		Iterator* p = new Iterator(trailer);
		return *p;
	}
	void insert(Iterator p, int data)
	{
		Node* newNode = new Node;
		Node* u = p.v->prev;
		newNode->data = data;

		newNode->next = p.v;
		p.v->prev = newNode;
		u->next = newNode;
		newNode->prev = u;
	}
	void insertFront(int data)
	{
		insert(begin(), data);
	}
	void insertBack(int data)
	{
		insert(end(), data);
	}
	void erase(Iterator p)
	{
		Node* u = p.v->prev;
		Node* n = p.v->next;
		u->next = n;
		n->prev = u;

		p = begin();
	}
	void eraseFront()
	{
		erase(begin());
	}
	void eraseBack()
	{
		erase(end());
	}
	void print()
	{
		Iterator p = begin();
		while (p != end())
		{
			cout << p.v->data << " ";
			++p;
		}
	}
	Iterator atIndex(int index)
	{
		Iterator p = begin();
		for (int i = 0; i < index; i++)
		{
			++p;
		}
		return p;
	}
	int IndexOf(Iterator q)
	{
		Iterator p = begin();
		int index = 0;
		while (p != q)
		{
			index++;
		}
		return index;
	}
	int max()
	{
		int max = begin().v->data;
		Iterator p = begin();
		while (p != end())
		{
			if (p.v->data > max)
				max = p.v->data;
			++p;
		}
		return max;
	}
	int min()
	{
		int min = begin().v->data;
		Iterator p = begin();
		while (p != end())
		{
			if (p.v->data < min)
				min = p.v->data;
			++p;
		}
		return min;
	}
	int average()
	{
		int total = 0;
		int count = 0;
		Iterator p = begin();
		while (p != end())
		{
			total += p.v->data;
			count++;
			++p;
		}
		return total / count;
	}
};

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		DoublyLinkedList* list = new DoublyLinkedList();
		int N;
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			int data;
			cin >> data;
			list->insertBack(data);
		}
		cout << list->average() << " " << list->min() << endl;
		delete list;
	}
	return 0;
}