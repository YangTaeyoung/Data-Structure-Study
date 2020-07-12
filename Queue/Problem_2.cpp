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
	int dequeue()
	{
		if (isEmpty())
			return -1;
		else
		{
			n--;
			return list->removeFront();
		}
	}
	void setQueue(int idx, int data)
	{
		
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

class Game
{
public:
	Queue* p1;
	Queue* p2;
	int p1_point;
	int p2_point;
	int size;
	Game(int size)
	{
		this->size = size;
		p1 = new Queue(size);
		p2 = new Queue(size);
		p1_point = 0;
		p2_point = 0;
	}
	~Game()
	{
		delete p1;
		delete p2;
	}
	void p1_draw(int card)
	{
		p1->enqueue(card);
	}
	void p2_draw(int card)
	{
		p2->enqueue(card);
	}
	void compare()
	{
		for (int i = 0; i < size; i++)
		{
			int p1_card = p1->dequeue();
			int p2_card = p2->dequeue();
			if (p1_card > p2_card)
			{
				p1_point++;
				if(i < size -1)
					p1->list->head->data += (p1_card - p2_card -1);
			}
			else if (p1_card < p2_card)
			{
				p2_point++;
				if (i < size - 1)
					p2->list->head->data += (p2_card - p1_card -1);
			}
		}

		if (p1_point > p2_point)
			cout << 1 << endl;
		else if (p1_point < p2_point)
			cout << 2 << endl;
		else
			cout << 0 << endl;
	}
};

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int card;
		cin >> card;
		Game* g = new Game(card);
		for (int i = 0; i < card; i++)
		{
			int data;
			cin >> data;
			g->p1_draw(data);
		}
		for (int i = 0; i < card; i++)
		{
			int data;
			cin >> data;
			g->p2_draw(data);
		}
		g->compare();

		delete g;
	}
	return 0;
}


