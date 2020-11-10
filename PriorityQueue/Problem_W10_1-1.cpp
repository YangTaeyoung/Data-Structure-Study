#include <iostream>
#include <vector>
using namespace std; 

enum direction { MIN = 1, MAX = -1 };
class Heap
{
private:
	vector<int>v;
	int heap_size;
	int root_index;
	int direction;
	
public:
	Heap(int direction)
	{
		v.push_back(-1);
		this->heap_size = 0;
		this->root_index = 1;
		this->direction = direction;
	}
	
	void swap(int idx1, int idx2)
	{
		v[0] = v[idx1];
		v[idx1] = v[idx2];
		v[idx2] = v[0];
	}
	void upHeap(int idx)
	{
		if (idx == root_index) return;
		else
		{
			int parent = idx / 2;
			if (v[parent] * direction > v[idx] * direction)
			{
				swap(parent, idx);
				upHeap(parent);
			}
		}
	}
	void downHeap(int idx)
	{
		int left = idx * 2;
		int right = idx * 2 + 1;
		
		if (right <= heap_size)
		{
			if (v[left] * direction <= v[right] * direction)
			{
				if (v[left] * direction < v[idx] * direction)
				{
					swap(left, idx);
					downHeap(left);
				}
				else return;
			}
			else
			{
				if (v[right] * direction < v[idx] * direction)
				{
					swap(right, idx);
					downHeap(right);
				}
				else return;
			}
		}
		else if (left <= heap_size)
		{
			if (v[left] * direction < v[idx] * direction)
			{
				swap(left, idx);
				downHeap(left);
			}
			else return;
		}
		else return;
	}
	
	void insert(int e)
	{
		v.push_back(e);
		heap_size++;
		upHeap(heap_size);
	}
	int pop()
	{
		if (isEmpty())
			return -1;
		int top = v[root_index];
		v[root_index] = v[heap_size];
		heap_size--;
		v.pop_back();
		downHeap(root_index);
		return top;
	}
	int top()
	{
		if (isEmpty())
		{
			return -1;
		}
		else
			return v[root_index];
	}
	int size()
	{
		return heap_size;
	}
	bool isEmpty()
	{
		return heap_size == 0;
	}
	void print()
	{
		if (isEmpty())
		{
			cout << -1 << endl;
		}
		else
		{
			for (int i = root_index; i < heap_size; i++)
			{
				cout << v[i] << " ";
			}
			cout << v[heap_size] << endl;
		}
	}
	int find(int x)
	{
		if (isEmpty())
		{
			return -1;
		}
		else
		{
			return v.at(x);
		}
	}
};
int main()
{
	int N;
	cin >> N;
	
	Heap PQ(MAX);

	for (int i = 0; i < N; i++)
	{
		string operation;
		cin >> operation;
		if (operation == "isEmpty")
		{
			cout << PQ.isEmpty() << endl;
		}
		else if (operation == "size")
		{
			cout << PQ.size() << endl;
		}
		else if (operation == "insert")
		{
			int elem;
			cin >> elem;
			PQ.insert(elem);
		}
		else if (operation == "pop")
		{
			cout << PQ.pop() << endl;
		}
		else if (operation == "print")
		{
			PQ.print();
		}
		else if (operation == "top")
		{
			cout << PQ.top() << endl;
		}
	}
}
