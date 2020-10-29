#include<iostream>
using namespace std;

class Stack
{
private: 
	int* data;
	int N;
	int cur;
public:
	Stack(int N)
	{
		cur = 0;
		this->N = N;
		data = new int[N];
		for (int i = 0; i < N; i++)
		{
			data[i] = 0;
		}
	}
	bool empty()
	{
		
		return cur == 0;
	}
	int top()
	{
		if (empty())	return -1;
		return data[cur-1];
	}
	void push(int X)
	{
		data[cur] = X;
		cur++;
	}
	int pop()
	{
		if (empty())	return -1;
		cur--;
		return data[cur];
	}
	int size()
	{
		return cur;
	}
};

int main()
{
	int N;
	cin >> N;
	Stack* stack = new Stack(10000);
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