#include<iostream>
using namespace std;
class Queue
{
private:
	int* data;
	int f;
	int r;
	int N;
public:
	Queue(int N)
	{
		this->N = N;
		data = new int[N];
		f = 0;
		r = 0;
	}
	bool full()
	{
		return (r - f) == N;
	}
	bool empty()
	{
		return (r - f) == 0;
	}
	int front()
	{
		return data[f % N];
	}
	int rear()
	{
		return data[(r-1) % N];
	}
	int size()
	{
		return r - f;
	}
	void enqueue(int X)
	{
		if (full())
			cout << "Full" << endl;
		else
		{
			data[r % N] = X;
			r++;
		}
			
	}
	void dequeue()
	{
		if (empty())
			cout << "Empty" << endl;
		else
		{ 
			cout << data[f % N] << endl;
			f++;
		}
	}
};

int main()
{
	int S, N;
	cin >> S >> N;
	Queue* queue = new Queue(S);
	for (int i = 0; i < N; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "isEmpty")
		{
			cout << (int)(queue->empty()) << endl;
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
	delete queue;
	return 0;
}