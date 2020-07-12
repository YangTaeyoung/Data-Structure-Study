#include<iostream>
using namespace std;

class Arr
{
public:
	int* arr;
	int size;
	Arr(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 0; i < size; i++)
		{
			arr[i] = 0;
		}
	}
	int at(int idx)
	{
		return arr[idx];
	}
	void set(int idx, int X)
	{
		if (arr[idx] == 0)
			cout << 0 << endl;
		else
			arr[idx] = X;
	}
	void add(int idx, int X)
	{
		if (arr[idx] == 0)
		{
			for (int i = 0; i < size; i++)
			{
				if (arr[i] == 0)
				{
					arr[i] = X;
					break;
				}
			}
		}
		else
		{
			for (int i = size - 2; i >= idx; i--)
			{
				arr[i + 1] = arr[i];
			}
			arr[idx] = X;
		}
	}
	void remove(int idx)
	{
		if (arr[idx] == 0)
		{
			cout << arr[idx] << endl;
			return;
		}
		cout << arr[idx] << endl;
		for (int i = idx; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}
	}
	void printArray()
	{
		if (arr[0] == 0)
		{
			cout << 0 << endl;
			return;
		}
		for (int i = 0; arr[i] != 0; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	Arr* arr = new Arr(10000);
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "remove")
		{
			int idx;
			cin >> idx;
			arr->remove(idx);
		}
		else if (operation == "printArray")
		{
			arr->printArray();
		}
		else if (operation == "add")
		{
			int idx;
			cin >> idx;
			int data;
			cin >> data;
			arr->add(idx, data);
		}
		else if (operation == "at")
		{
			int idx;
			cin >> idx;
			cout << arr->at(idx) << endl;
		}
		else if (operation == "set")
		{
			int idx;
			cin >> idx;
			int data;
			cin >> data;
			arr->set(idx, data);
		}
	}
}
