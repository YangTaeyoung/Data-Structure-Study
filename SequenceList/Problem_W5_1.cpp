#include <iostream>
using namespace std;

class Node
{
private:
	int data;
	Node* next;
	Node* prev;
public:
	Node(int data)
	{
		this->data = data;
		next = nullptr;
		prev = nullptr;
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
	Node* getPrev()
	{
		return prev;
	}
	void setPrev(Node* prev)
	{
		this->prev = prev;
	}
};
class  SequenceList
{
private:
	Node* header; // 머리 노드
	Node* trailer; // 꼬리 노드
	int idx; // 현재 인덱스
	int n; // 현재 저장된 원소의 개수
public:
	SequenceList()
	{
		header = new Node(0);
		trailer = new Node(0);
		header->setNext(trailer);
		trailer->setPrev(header);
		idx = 0;
		n = 0;
	}
	int size()
	{
		return n;
	}
	bool empty()
	{
		return size() == 0;
	}
	int getIndex()
	{
		return idx;
	}
	void setIndex(int idx)
	{
		this->idx = idx;
	}
	Node* atIndex(int index)
	{
		Node* tmp = header->getNext();
		for (int i = 0; i < index; i++)
		{
			if(tmp != nullptr)
				tmp = tmp->getNext();
		}
		return tmp;
	}
	int indexOf(Node* node)
	{
		Node* tmp = header->getNext();
		int index = 0;
		while (tmp!=node)
		{
			tmp = tmp->getNext();
			index++;
		}
		return index;
	}
	Node* begin()
	{
		idx = 0;
		return header->getNext();
	}
	Node* end()
	{
		idx = n;
		return trailer;
	}
	void insert(Node* cur, int data)
	{
		Node* p = cur->getPrev();
		Node* c = cur;
		Node* newNode = new Node(data);
		p->setNext(newNode);
		newNode->setPrev(p);
		newNode->setNext(c);
		c->setPrev(newNode);
		idx++;
		n++;
	}
	void insertFront(int data)
	{
		Node* newNode = new Node(data);
		insert(begin(), data);
	}
	void insertBack(int data)
	{
		insert(end(), data);
	}
	void erase(Node* cur)
	{
		if (empty())
		{
			cout << "Empty" << endl;
			return;
		}
		Node* p = cur->getPrev();
		Node* nxt = cur->getNext();
		p->setNext(nxt);
		nxt->setPrev(p);
		idx = 0;
		n--;
		delete cur;
	}
	void eraseFront()
	{
		erase(begin());
	}
	void eraseBack()
	{
		erase(end());
	}
	void plus()
	{
		if(idx != n)
			idx++;
	}
	void minus()
	{
		if(idx != 0)
			idx--;
	}
	void print()
	{
		if(empty())
		{
			cout << "Empty" << endl;
			return;
		}
		for (Node* tmp = header->getNext(); tmp != trailer; tmp = tmp->getNext())
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
	SequenceList* seql = new SequenceList();
	for (int i = 0; i < N; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "insert")
		{
			int data;
			cin >> data;
			seql->insert(seql->atIndex(seql->getIndex()), data);
		}
		else if (operation == "print")
		{
			seql->print();
		}
		else if (operation == "begin")
		{
			seql->begin();
		}
		else if (operation == "end")
		{
			seql->end();
		}
		else if (operation == "erase")
		{
			seql->erase(seql->atIndex(seql->getIndex()));
		}
		else if (operation == "size")
		{
			cout << seql->size() << endl;
		}
		else if (operation == "++")
		{
			seql->plus();
		}
		else if (operation == "--")
		{
			seql->minus();
		}
	}
	delete seql;
	return 0;
}