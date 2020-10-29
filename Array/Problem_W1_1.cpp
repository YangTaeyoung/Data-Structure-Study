#include<iostream>
using namespace std;

class Array
{
private:
	int * data;
	int size;
	int n;
public:
	Array(int size)
	{
		this->n = 0;
		this->size = size;
		this->data = new int[size];
		for (int i = 0; i < size; i++)
		{
			data[i] = 0;
		}
	}
	int at(int i)
	{
		return data[i];
	}
	void set(int i, int X)
	{
		if (data[i] == 0)
		{
			cout << 0 << endl;
		}
		else
		{
			data[i] = X;
		}
	}
	void add(int index, int X)
	{
		if (data[index] == 0)
		{
			for (int i = 0; i < size; i++)
			{
				if (data[i] == 0)
				{
					data[i] = X;
					n++;
					return;
				}
			}
		}
		else
		{
			for (int i = n - 1; i >= index; i--)
			{
				if(i+1 != size)
				{
					data[i + 1] = data[i];
				}
			}
			data[index] = X;
			n++;
		}
	}
};

int main()
{
	int M;
	cin >> M;
	Array *arr = new Array(10000);
	for (int i = 0; i < M; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "add")
		{
			int i, data = 0;
			cin >> i >> data;
			arr->add(i, data);
		}
		else if (operation == "set")
		{
			int i, data = 0;
			cin >> i >> data;
			arr->set(i, data);
		}
		else if (operation == "at")
		{

			int i =0;
			cin >> i;
			cout << arr->at(i) << endl;
		}
	}
	delete arr;
	return 0;
}